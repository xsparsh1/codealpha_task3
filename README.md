Banking Management System in C++
This project is a console-based Banking Management System built in C++. It allows the creation of customer accounts, deposits, withdrawals, and viewing of detailed account information along with transaction history.

Features
Customer & Account Creation:
Capture customer name, ID, account number, type, and initial balance.

Deposit Money:
Add funds to an existing account with automatic transaction logging.

Withdraw Money:
Withdraw funds with balance check and transaction recording.

View Account Details:
Display full customer information, account details, and all past transactions with timestamps.

Transaction History:
Each transaction (deposit/withdraw) is logged with date & time.

Class Structure
1. Transaction
Records type (Deposit or Withdraw), amount, and timestamp.
Has a print() method to display transactions.

2. Account
Holds account number, type, balance, and list of transactions.
Functions for deposit, withdraw, and viewing details.

3. Customer
Contains customer name, ID, and an account object.

Future Enhancements
Store customer and transaction data in files or a database
Add login and role-based access
Add GUI or web interface
Export transaction history as CSV or PDF
Displays complete customer profile and account info.

5. BankSystem
Manages a list of customers.
Provides a menu-driven interface to access all banking operations.
