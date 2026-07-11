#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

void displayMainMenu() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║         BANKING MANAGEMENT SYSTEM                      ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║  1. Create Account                                     ║" << endl;
    cout << "║  2. Login to Account                                   ║" << endl;
    cout << "║  3. Deposit Money                                      ║" << endl;
    cout << "║  4. Withdraw Money                                     ║" << endl;
    cout << "║  5. Transfer Money                                     ║" << endl;
    cout << "║  6. Check Balance                                      ║" << endl;
    cout << "║  7. Transaction History                                ║" << endl;
    cout << "║  8. Update Customer Details                            ║" << endl;
    cout << "║  9. View All Accounts                                  ║" << endl;
    cout << "║  10. Delete Account                                    ║" << endl;
    cout << "║  0. Exit                                               ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Bank bank("Banking Management System");
    int choice;
    string accountNumber, name, email, phone, address, dob, accountType;
    double amount;

    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║     WELCOME TO BANKING MANAGEMENT SYSTEM               ║" << endl;
    cout << "║     Developed in C++ with OOP Principles               ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    while (true) {
        displayMainMenu();
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1: {
                // Create Account
                cout << "\n========== CREATE NEW ACCOUNT ==========" << endl;
                cout << "Enter your name: ";
                getline(cin, name);

                cout << "Enter your email: ";
                getline(cin, email);

                cout << "Enter your phone number: ";
                getline(cin, phone);

                cout << "Enter your address: ";
                getline(cin, address);

                cout << "Enter your date of birth (DD/MM/YYYY): ";
                getline(cin, dob);

                cout << "Select account type (Savings/Checking/Business): ";
                getline(cin, accountType);

                cout << "Enter initial deposit amount: Rs.";
                cin >> amount;

                if (amount >= 0) {
                    bank.createAccount(name, email, phone, address, dob, accountType, amount);
                } else {
                    cout << "\n✗ Initial deposit cannot be negative!" << endl;
                }
                break;
            }

            case 2: {
                // Login to Account
                cout << "\n========== LOGIN TO ACCOUNT ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);
                bank.loginAccount(accountNumber);
                break;
            }

            case 3: {
                // Deposit Money
                cout << "\n========== DEPOSIT MONEY ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);

                cout << "Enter deposit amount (Rs.): ";
                cin >> amount;

                if (amount > 0) {
                    bank.depositMoney(accountNumber, amount);
                } else {
                    cout << "\n✗ Deposit amount must be positive!" << endl;
                }
                break;
            }

            case 4: {
                // Withdraw Money
                cout << "\n========== WITHDRAW MONEY ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);

                cout << "Enter withdrawal amount (Rs.): ";
                cin >> amount;

                if (amount > 0) {
                    bank.withdrawMoney(accountNumber, amount);
                } else {
                    cout << "\n✗ Withdrawal amount must be positive!" << endl;
                }
                break;
            }

            case 5: {
                // Transfer Money
                cout << "\n========== TRANSFER MONEY ==========" << endl;
                cout << "Enter your account number (From): ";
                getline(cin, accountNumber);

                string toAccount;
                cout << "Enter recipient account number (To): ";
                getline(cin, toAccount);

                cout << "Enter transfer amount (Rs.): ";
                cin >> amount;

                if (amount > 0) {
                    bank.transferMoney(accountNumber, toAccount, amount);
                } else {
                    cout << "\n✗ Transfer amount must be positive!" << endl;
                }
                break;
            }

            case 6: {
                // Check Balance
                cout << "\n========== CHECK BALANCE ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);
                bank.checkBalance(accountNumber);
                break;
            }

            case 7: {
                // Transaction History
                cout << "\n========== TRANSACTION HISTORY ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);
                bank.displayTransactionHistory(accountNumber);
                break;
            }

            case 8: {
                // Update Customer Details
                cout << "\n========== UPDATE CUSTOMER DETAILS ==========" << endl;
                cout << "Enter your account number: ";
                getline(cin, accountNumber);

                cout << "Enter new name (press Enter to skip): ";
                getline(cin, name);

                cout << "Enter new email (press Enter to skip): ";
                getline(cin, email);

                cout << "Enter new phone (press Enter to skip): ";
                getline(cin, phone);

                cout << "Enter new address (press Enter to skip): ";
                getline(cin, address);

                bank.updateCustomerDetails(accountNumber, name, email, phone, address);
                break;
            }

            case 9: {
                // View All Accounts
                bank.displayAllAccounts();
                break;
            }

            case 10: {
                // Delete Account
                cout << "\n========== DELETE ACCOUNT ==========" << endl;
                cout << "Enter account number to delete: ";
                getline(cin, accountNumber);

                cout << "Are you sure? This action cannot be undone. (yes/no): ";
                string confirm;
                getline(cin, confirm);

                if (confirm == "yes" || confirm == "Yes") {
                    bank.deleteAccount(accountNumber);
                } else {
                    cout << "\n✓ Account deletion cancelled." << endl;
                }
                break;
            }

            case 0: {
                // Exit
                cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
                cout << "║         Thank you for using Banking System!            ║" << endl;
                cout << "║                  Goodbye!                              ║" << endl;
                cout << "╚════════════════════════════════════════════════════════╝" << endl;
                return 0;
            }

            default: {
                cout << "\n✗ Invalid choice! Please try again." << endl;
            }
        }
    }

    return 0;
}
