#include "Bank.h"
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

// Constructor
Bank::Bank(string name, string accFile, string transFile)
    : bankName(name), accountsFile(accFile), transactionsFile(transFile) {
    loadAllAccounts();
}

// Helper function to generate Account Number
void Bank::generateAccountNumber(string& accountNumber) {
    srand(time(0) + rand());
    ostringstream oss;
    oss << "ACC" << time(0) << rand() % 10000;
    accountNumber = oss.str();
}

// Find account index by account number
int Bank::findAccountIndex(string accountNumber) const {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1;
}

// Create new account
bool Bank::createAccount(string name, string email, string phone, string address, string dob, string accountType, double initialBalance) {
    string accountNumber;
    generateAccountNumber(accountNumber);

    Customer newCustomer(accountNumber, name, email, phone, address, dob, accountType);
    Account newAccount(newCustomer, initialBalance);
    
    accounts.push_back(newAccount);
    accountIndexMap[accountNumber] = accounts.size() - 1;

    cout << "\n✓ Account created successfully!" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Initial Balance: Rs." << fixed << setprecision(2) << initialBalance << endl;

    saveAllAccounts();
    return true;
}

// Login to account
bool Bank::loginAccount(string accountNumber, string password) {
    int index = findAccountIndex(accountNumber);
    if (index != -1 && accounts[index].getIsActive()) {
        cout << "\n✓ Login successful!" << endl;
        accounts[index].displayAccountInfo();
        return true;
    }
    cout << "\n✗ Account not found or inactive!" << endl;
    return false;
}

// Delete account
bool Bank::deleteAccount(string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].setActive(false);
        cout << "\n✓ Account deleted successfully!" << endl;
        saveAllAccounts();
        return true;
    }
    cout << "\n✗ Account not found!" << endl;
    return false;
}

// Update customer details
bool Bank::updateCustomerDetails(string accountNumber, string name, string email, string phone, string address) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        Customer cust = accounts[index].getCustomer();
        if (!name.empty()) cust.setName(name);
        if (!email.empty()) cust.setEmail(email);
        if (!phone.empty()) cust.setPhone(phone);
        if (!address.empty()) cust.setAddress(address);
        
        accounts[index].setCustomer(cust);
        cout << "\n✓ Customer details updated successfully!" << endl;
        saveAllAccounts();
        return true;
    }
    cout << "\n✗ Account not found!" << endl;
    return false;
}

// Deposit money
bool Bank::depositMoney(string accountNumber, double amount) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        return accounts[index].deposit(amount);
    }
    cout << "\n✗ Account not found!" << endl;
    return false;
}

// Withdraw money
bool Bank::withdrawMoney(string accountNumber, double amount) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        return accounts[index].withdraw(amount);
    }
    cout << "\n✗ Account not found!" << endl;
    return false;
}

// Transfer money
bool Bank::transferMoney(string fromAccount, string toAccount, double amount) {
    int fromIndex = findAccountIndex(fromAccount);
    int toIndex = findAccountIndex(toAccount);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "\n✗ One or both accounts not found!" << endl;
        return false;
    }

    return accounts[fromIndex].transfer(accounts[toIndex], amount);
}

// Check balance
double Bank::checkBalance(string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        double balance = accounts[index].getBalance();
        cout << "\n========== BALANCE INQUIRY ==========" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs." << fixed << setprecision(2) << balance << endl;
        cout << "====================================\n" << endl;
        return balance;
    }
    cout << "\n✗ Account not found!" << endl;
    return -1.0;
}

// Display transaction history
void Bank::displayTransactionHistory(string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].displayTransactionHistory();
        return;
    }
    cout << "\n✗ Account not found!" << endl;
}

// Save all accounts to file
void Bank::saveAllAccounts() {
    ofstream outFile(accountsFile);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open accounts file for writing!" << endl;
        return;
    }

    for (const auto& account : accounts) {
        if (account.getIsActive()) {
            outFile << account.serializeAccount() << endl;
        }
    }
    outFile.close();
}

// Load all accounts from file
void Bank::loadAllAccounts() {
    ifstream inFile(accountsFile);
    if (!inFile.is_open()) {
        // File doesn't exist yet, that's okay
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            Account acc = Account::deserializeAccount(line);
            accounts.push_back(acc);
            accountIndexMap[acc.getAccountNumber()] = accounts.size() - 1;
        }
    }
    inFile.close();
}

// Display all accounts
void Bank::displayAllAccounts() const {
    if (accounts.empty()) {
        cout << "\n✗ No accounts found!" << endl;
        return;
    }

    cout << "\n========== ALL ACCOUNTS ==========" << endl;
    cout << left << setw(15) << "Account No" << setw(20) << "Name" 
         << setw(15) << "Type" << setw(15) << "Balance" << endl;
    cout << "=====================================" << endl;

    for (const auto& account : accounts) {
        if (account.getIsActive()) {
            cout << left << setw(15) << account.getAccountNumber()
                 << setw(20) << account.getCustomerName()
                 << setw(15) << account.getCustomer().getAccountType()
                 << "Rs." << fixed << setprecision(2) << account.getBalance() << endl;
        }
    }
    cout << "=====================================\n" << endl;
}

// Display account details
void Bank::displayAccountDetails(string accountNumber) const {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        accounts[index].displayAccountInfo();
        return;
    }
    cout << "\n✗ Account not found!" << endl;
}

// Getters
string Bank::getBankName() const {
    return bankName;
}

int Bank::getTotalAccounts() const {
    int count = 0;
    for (const auto& account : accounts) {
        if (account.getIsActive()) count++;
    }
    return count;
}

Account* Bank::getAccount(string accountNumber) {
    int index = findAccountIndex(accountNumber);
    if (index != -1) {
        return &accounts[index];
    }
    return nullptr;
}
