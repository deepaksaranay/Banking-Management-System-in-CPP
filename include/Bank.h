#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Account.h"
#include "Customer.h"

using namespace std;

class Bank {
private:
    string bankName;
    vector<Account> accounts;
    map<string, int> accountIndexMap;  // Maps account number to index in accounts vector
    string accountsFile;
    string transactionsFile;

    // Helper functions
    int findAccountIndex(string accountNumber) const;
    void generateAccountNumber(string& accountNumber);
    void saveAllAccounts();
    void loadAllAccounts();

public:
    // Constructor
    Bank(string name = "Banking System", string accFile = "data/accounts.txt", string transFile = "data/transactions.txt");

    // Account operations
    bool createAccount(string name, string email, string phone, string address, string dob, string accountType, double initialBalance);
    bool loginAccount(string accountNumber, string password = "");
    bool deleteAccount(string accountNumber);
    bool updateCustomerDetails(string accountNumber, string name, string email, string phone, string address);

    // Transaction operations
    bool depositMoney(string accountNumber, double amount);
    bool withdrawMoney(string accountNumber, double amount);
    bool transferMoney(string fromAccount, string toAccount, double amount);
    double checkBalance(string accountNumber);
    void displayTransactionHistory(string accountNumber);

    // File operations
    void saveToFile();
    void loadFromFile();

    // Display operations
    void displayAllAccounts() const;
    void displayAccountDetails(string accountNumber) const;

    // Getter
    string getBankName() const;
    int getTotalAccounts() const;
    Account* getAccount(string accountNumber);
};

#endif // BANK_H
