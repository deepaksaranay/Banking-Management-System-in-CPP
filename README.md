# Banking Management System in C++

A console-based Banking Management System developed in C++ using Object-Oriented Programming (OOP), file handling, and a menu-driven interface for managing customer accounts, transactions, and banking operations.

## 🎯 Features

- ✅ **Create Account** - Register a new customer account
- ✅ **Login** - Access your account securely
- ✅ **Deposit Money** - Add funds to your account
- ✅ **Withdraw Money** - Withdraw funds with overdraft protection
- ✅ **Transfer Money** - Send money between accounts
- ✅ **Balance Inquiry** - Check current account balance
- ✅ **Transaction History** - View all transactions
- ✅ **Update Customer Details** - Modify account information
- ✅ **Delete Account** - Close your account
- ✅ **File-Based Storage** - Persistent data storage
- ✅ **Menu-Driven Interface** - User-friendly console interface

## 🛠️ Technologies Used

- **Language:** C++11/14
- **Paradigm:** Object-Oriented Programming (OOP)
- **Data Handling:** File I/O (std::fstream)
- **Collections:** Standard Template Library (STL)
- **Compiler:** GCC/G++
- **Build Tool:** Makefile

## 📁 Project Structure

```
Banking-Management-System-in-CPP/
│
├── include/
│   ├── Account.h         # Account class definition
│   ├── Customer.h        # Customer class definition
│   └── Bank.h            # Bank class definition
│
├── src/
│   ├── main.cpp          # Main application with menu system
│   ├── Bank.cpp          # Bank implementation
│   ├── Account.cpp       # Account implementation
│   └── Customer.cpp      # Customer implementation
│
├── data/
│   ├── accounts.txt      # Stores account data
│   └── transactions.txt  # Stores transaction records
│
├── README.md             # Project documentation
├── LICENSE               # MIT License
├── .gitignore            # Git ignore rules
└── Makefile              # Build configuration
```

## 🚀 Build Instructions

### Using Makefile:

```bash
# Compile the project
make

# Run the program
./banking

# Clean build files
make clean

# Clean everything including data
make clean-all
```

### Manual Compilation:

```bash
g++ -std=c++11 -I./include -o banking src/main.cpp src/Bank.cpp src/Account.cpp src/Customer.cpp
./banking
```

## 📋 How to Use

1. **Start the Program**
   ```bash
   ./banking
   ```

2. **Create Account**
   - Select option 1 from the main menu
   - Enter your personal details
   - Set initial deposit amount

3. **Perform Transactions**
   - Deposit: Add money to your account
   - Withdraw: Remove money (with overdraft protection)
   - Transfer: Send money to another account
   - Check Balance: View your current balance
   - View History: See all transactions

4. **Manage Account**
   - Update Details: Modify your information
   - Delete Account: Close your account permanently

## 💻 OOP Concepts Demonstrated

- **Encapsulation** - Private data members with public accessors
- **Classes & Objects** - Customer, Account, and Bank classes
- **Inheritance** - Potential for extending account types
- **Abstraction** - Hide complex file I/O operations
- **Modularity** - Separate header and source files
- **File Handling** - Persistent storage of accounts and transactions

## 📊 Skills Demonstrated

✅ Object-Oriented Programming (OOP)
✅ Classes & Objects Design
✅ Encapsulation & Data Hiding
✅ File Handling & I/O Operations
✅ CRUD Operations (Create, Read, Update, Delete)
✅ Banking Logic Implementation
✅ Menu-Driven Applications
✅ Modular Programming
✅ Error Handling
✅ Data Validation

## 🎓 Project Difficulty

⭐⭐⭐⭐☆ (Intermediate Level)

**Why this project is valuable for portfolios:**
- Demonstrates strong OOP fundamentals
- Shows practical business logic implementation
- Includes file handling for data persistence
- Implements real-world banking concepts
- Excellent for technical interviews

## 📝 File Descriptions

| File | Purpose |
|------|---------|
| `Account.h` | Defines the Account class and Transaction struct |
| `Customer.h` | Defines the Customer class |
| `Bank.h` | Defines the Bank class for system management |
| `main.cpp` | Menu system and user interface |
| `Bank.cpp` | Core banking operations and file management |
| `Account.cpp` | Account operations (deposit, withdraw, transfer) |
| `Customer.cpp` | Customer information management |
| `accounts.txt` | Persistent storage for account data |
| `transactions.txt` | Transaction history log |

## 🔒 Security Features

- Account-based access control
- Transaction validation
- Overdraft limit protection
- Data persistence and recovery
- Account deletion with confirmation

## 📈 Future Enhancements

- Password protection for accounts
- Interest calculation
- Loan management
- Multiple currency support
- Database integration (SQLite/MySQL)
- GUI using Qt/GTK
- Network banking capabilities

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request or open an issue for any bugs or feature requests.

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Deepak Saranay**

## ⭐ If you found this helpful, please star the repository!

---

**Last Updated:** July 11, 2026
**Status:** Complete & Production Ready
