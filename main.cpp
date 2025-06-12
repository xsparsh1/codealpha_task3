#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Transaction{
public:
    string type;
    double amount;
    string timestamp;
    Transaction(string t,double amt){
        type=t;
        amount=amt;
        timestamp=currentTime();
    }
    string currentTime(){
        time_t now=std::time(nullptr);
        char* dt=ctime(&now);
        string s(dt);
        s.pop_back();
        return s;
    }
    void print(){
        cout<<left<<setw(12)<<type<<"| Rs. "<<setw(10)<<amount<<" | "<<timestamp<<endl;
    }
};

class Account{
public:
    string accNumber;
    string accType;
    double balance;
    vector<Transaction> history;
    Account(string num,string type,double bal){
        accNumber=num;
        accType=type;
        balance=bal;
    }
    void deposit(double amount){
        balance+=amount;
        history.emplace_back("Deposit",amount);
    }
    bool withdraw(double amount){
        if(amount>balance) return false;
        balance-=amount;
        history.emplace_back("Withdraw",amount);
        return true;
    }
    void displayAccountDetails(){
        cout<<"\nAccount Number: "<<accNumber;
        cout<<"\nAccount Type: "<<accType;
        cout<<"\nBalance: Rs. "<<balance<<"\n";
    }
    void printTransactionHistory(){
        cout<<"\n--- Transaction History ---\n";
        for(auto &t:history) t.print();
    }
};

class Customer{
public:
    string name;
    string customerID;
    Account account;
    Customer(string n,string id,Account acc):name(n),customerID(id),account(acc){}
    void showCustomerInfo(){
        cout<<"\nCustomer Name: "<<name;
        cout<<"\nCustomer ID: "<<customerID;
        account.displayAccountDetails();
    }
};

class BankSystem{
    vector<Customer> customers;
public:
    void createCustomer(){
        string name,id,accNum,accType;
        double balance;
        cin.ignore();
        cout<<"Enter Name: ";
        getline(cin,name);
        cout<<"Enter Customer ID: ";
        getline(cin,id);
        cout<<"Enter Account Number: ";
        getline(cin,accNum);
        cout<<"Enter Account Type: ";
        getline(cin,accType);
        cout<<"Enter Initial Balance: ";
        cin>>balance;
        Account newAcc(accNum,accType,balance);
        Customer newCust(name,id,newAcc);
        customers.push_back(newCust);
        cout<<"\nCustomer and Account Created Successfully!\n";
    }
    Customer* findCustomer(const string &id){
        for(auto &cust:customers){
            if(cust.customerID==id) return &cust;
        }
        return nullptr;
    }
    void depositMoney(){
        string id; double amt;
        cout<<"Enter Customer ID: ";
        cin>>id;
        Customer* cust=findCustomer(id);
        if(cust){
            cout<<"Enter Amount to Deposit: ";
            cin>>amt;
            cust->account.deposit(amt);
            cout<<"Deposit successful.\n";
        }else cout<<"Customer not found.\n";
    }
    void withdrawMoney(){
        string id; double amt;
        cout<<"Enter Customer ID: ";
        cin>>id;
        Customer* cust=findCustomer(id);
        if(cust){
            cout<<"Enter Amount to Withdraw: ";
            cin>>amt;
            if(cust->account.withdraw(amt))
                cout<<"Withdrawal successful.\n";
            else
                cout<<"Insufficient balance.\n";
        }else cout<<"Customer not found.\n";
    }
    void viewAccountDetails(){
        string id;
        cout<<"Enter Customer ID: ";
        cin>>id;
        Customer* cust=findCustomer(id);
        if(cust){
            cust->showCustomerInfo();
            cust->account.printTransactionHistory();
        }else cout<<"Customer not found.\n";
    }
};

int main(){
    BankSystem bank;
    int choice;
    do{
        cout<<"\n----BANKING SYSTEM MENU----\n";
        cout<<"1. Create Customer and Account\n";
        cout<<"2. Deposit\n";
        cout<<"3. Withdraw\n";
        cout<<"4. View Account Details\n";
        cout<<"5. Exit\n";
        cout<<"Choose an option: ";
        cin>>choice;
        switch(choice){
            case 1: bank.createCustomer(); break;
            case 2: bank.depositMoney(); break;
            case 3: bank.withdrawMoney(); break;
            case 4: bank.viewAccountDetails(); break;
            case 5: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice. Try again.\n";
        }
    }while(choice!=5);
    return 0;
}
