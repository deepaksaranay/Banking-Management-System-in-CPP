#include "Account.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdlib>

// Transaction Struct Implementation
Transaction::Transaction() 
    : transactionID(""), type(""), amount(0.0), balanceAfter(0.0), 
      timestamp(0), description(""), status("") {}

Transaction::Transaction(string id, string t, double amt, double bal, long long time, string desc, string stat)
    : transactionID(id), type(t), amount(amt), balanceAfter(bal), 
      timestamp(time), description(desc), status(stat) {}

string Transaction::serialize() const {
    ostringstream oss;
    oss << transactionID << "|" << type << "|" << amount << "|" 
        << balanceAfter << "|" << timestamp << "|" << description << "|" << status;
    return oss.str();
}

Transaction Transaction::deserialize(string data) {
    stringstream ss(data);
    string token;
    vector<string> tokens;

    while (getline(ss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() >= 7) {
        Transaction trans;
        trans.transactionID = tokens[0];
        trans.type = tokens[1];
        trans.amount = stod(tokens[2]);
        trans.balanceAfter = stod(tokens[3]);
        trans.timestamp = stoll(tokens[4]);
        trans.description = tokens[5];
        trans.status = tokens[6];
        return trans;
    }

    return Transaction();
}

// Account Class Implementation
Account::Account() 
    : balance(0.0), overdraftLimit(0.0), isActive(true) {}

Account::Account(Customer cust, double initialBalance)
    : customer(cust), balance(initialBalance), overdraftLimit(0.0), isActive(true) {
    if (initialBalance > 0.0) {
        Transaction trans(generateTransactionID(), "Deposit", initialBalance, balance, time(nullptr), "Initial Deposit", "Success");
        transactions.push_back(trans);
    }
}

// Helper function to generate Transaction ID
static string generateTransactionID() {
    time_t now = time(nullptr);
    ostringstream oss;
    oss << "TXN" << now << rand() % 1000;
    return oss.str();
}

// Balance operations
bool Account::deposit(double amount, string description) {
    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive!" << endl;
        return false;
    }

    balance += amount;
    Transaction trans(generateTransactionID(), "Deposit", amount, balance, time(nullptr), description, "Success");
    transactions.push_back(trans);
    
    cout << "✓ Deposit successful! New balance: Rs." << fixed << setprecision(2) << balance << endl;
    return true;
}

bool Account::withdraw(double amount, string description) {
    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive!" << endl;
        return false;
    }

    if (balance - amount < -overdraftLimit) {
        cout << "Error: Insufficient funds! Available balance: Rs." << fixed << setprecision(2) << balance << endl;
        return false;
    }

    balance -= amount;
    Transaction trans(generateTransactionID(), "Withdrawal", amount, balance, time(nullptr), description, "Success");
    transactions.push_back(trans);
    
    cout << "✓ Withdrawal successful! New balance: Rs." << fixed << setprecision(2) << balance << endl;
    return true;
}

bool Account::transfer(Account& recipient, double amount) {
    if (amount <= 0) {
        cout << "Error: Transfer amount must be positive!" << endl;
        return false;
    }

    if (balance - amount < -overdraftLimit) {
        cout << "Error: Insufficient funds for transfer!" << endl;
        return false;
    }

    // Deduct from sender
    balance -= amount;
    Transaction senderTrans(generateTransactionID(), "Transfer", amount, balance, time(nullptr), 
                           "Transfer to " + recipient.getAccountNumber(), "Success");
    transactions.push_back(senderTrans);

    // Add to recipient
    recipient.balance += amount;
    Transaction recipientTrans(generateTransactionID(), "Transfer", amount, recipient.balance, time(nullptr), 
                              "Transfer from " + customer.getAccountNumber(), "Success");
    recipient.transactions.push_back(recipientTrans);

    cout << "✓ Transfer successful! Transferred Rs." << fixed << setprecision(2) << amount 
         << " to " << recipient.getCustomerName() << endl;
    return true;
}

double Account::getBalance() const {
    return balance;
}

// Account management
void Account::setActive(bool status) {
    isActive = status;
}

bool Account::getIsActive() const {
    return isActive;
}

void Account::setOverdraftLimit(double limit) {
    overdraftLimit = limit;
}

double Account::getOverdraftLimit() const {
    return overdraftLimit;
}

// Customer operations
Customer Account::getCustomer() const {
    return customer;
}

void Account::setCustomer(Customer cust) {
    customer = cust;
}

// Transaction history
vector<Transaction> Account::getTransactionHistory() const {
    return transactions;
}

void Account::addTransaction(Transaction trans) {
    transactions.push_back(trans);
}

void Account::displayTransactionHistory() const {
    if (transactions.empty()) {
        cout << "No transactions found." << endl;
        return;
    }

    cout << "\n========== TRANSACTION HISTORY ==========" << endl;
    cout << left << setw(15) << "Type" << setw(12) << "Amount" 
         << setw(15) << "Balance" << setw(25) << "Description" << endl;
    cout << "===========================================" << endl;

    for (const auto& trans : transactions) {
        cout << left << setw(15) << trans.type 
             << "Rs." << setw(10) << fixed << setprecision(2) << trans.amount
             << "Rs." << setw(13) << fixed << setprecision(2) << trans.balanceAfter
             << trans.description << endl;
    }
    cout << "==========================================\n" << endl;
}

// Display account info
void Account::displayAccountInfo() const {
    cout << "\n========== ACCOUNT INFORMATION ==========" << endl;
    customer.displayInfo();
    cout << "Current Balance: Rs." << fixed << setprecision(2) << balance << endl;
    cout << "Overdraft Limit: Rs." << fixed << setprecision(2) << overdraftLimit << endl;
    cout << "Account Status: " << (isActive ? "Active" : "Inactive") << endl;
    cout << "Total Transactions: " << transactions.size() << endl;
    cout << "=========================================\n" << endl;
}

// Getters
string Account::getAccountNumber() const {
    return customer.getAccountNumber();
}

string Account::getCustomerName() const {
    return customer.getName();
}

// Serialize/Deserialize
string Account::serializeAccount() const {
    ostringstream oss;
    oss << customer.serialize() << "|" << balance << "|" << overdraftLimit << "|" << isActive << "|";
    
    for (const auto& trans : transactions) {
        oss << trans.serialize() << ";";
    }
    
    return oss.str();
}

Account Account::deserializeAccount(string data) {
    size_t pipePos = data.rfind('|');
    if (pipePos == string::npos) return Account();

    string customerData = data.substr(0, data.find('|', data.find('|') + 1));
    // Implementation would parse the data accordingly
    return Account();
}
