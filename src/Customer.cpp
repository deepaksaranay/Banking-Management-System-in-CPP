#include "Customer.h"
#include <ctime>
#include <sstream>

// Constructor
Customer::Customer() 
    : accountNumber(""), name(""), email(""), phone(""), 
      address(""), dateOfBirth(""), accountType(""), creationDate(0) {}

Customer::Customer(string accNo, string n, string e, string p, string addr, string dob, string type)
    : accountNumber(accNo), name(n), email(e), phone(p), 
      address(addr), dateOfBirth(dob), accountType(type), creationDate(time(nullptr)) {}

// Getters
string Customer::getAccountNumber() const {
    return accountNumber;
}

string Customer::getName() const {
    return name;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getAddress() const {
    return address;
}

string Customer::getDateOfBirth() const {
    return dateOfBirth;
}

string Customer::getAccountType() const {
    return accountType;
}

long long Customer::getCreationDate() const {
    return creationDate;
}

// Setters
void Customer::setName(string n) {
    name = n;
}

void Customer::setEmail(string e) {
    email = e;
}

void Customer::setPhone(string p) {
    phone = p;
}

void Customer::setAddress(string addr) {
    address = addr;
}

void Customer::setAccountNumber(string accNo) {
    accountNumber = accNo;
}

void Customer::setAccountType(string type) {
    accountType = type;
}

void Customer::setCreationDate(long long date) {
    creationDate = date;
}

// Display customer info
void Customer::displayInfo() const {
    cout << "\n========== CUSTOMER INFORMATION ==========" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "=========================================\n" << endl;
}

// Serialize to string (for file storage)
string Customer::serialize() const {
    ostringstream oss;
    oss << accountNumber << "|" << name << "|" << email << "|" 
        << phone << "|" << address << "|" << dateOfBirth << "|" 
        << accountType << "|" << creationDate;
    return oss.str();
}

// Deserialize from string (from file storage)
Customer Customer::deserialize(string data) {
    stringstream ss(data);
    string token;
    vector<string> tokens;

    while (getline(ss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() >= 8) {
        Customer cust;
        cust.setAccountNumber(tokens[0]);
        cust.setName(tokens[1]);
        cust.setEmail(tokens[2]);
        cust.setPhone(tokens[3]);
        cust.setAddress(tokens[4]);
        cust.dateOfBirth = tokens[5];
        cust.setAccountType(tokens[6]);
        cust.setCreationDate(stoll(tokens[7]));
        return cust;
    }

    return Customer();
}
