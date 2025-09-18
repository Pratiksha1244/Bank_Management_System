#include <iostream>
#include <string>
#include <map>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Default constructor
    BankAccount() : accountHolderName(""), accountNumber(0), balance(0.0) {}
    //Parameterized Constructor
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNo;
        balance = initialBalance;
    
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully! New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully! Remaining balance: " << balance << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal!" << endl;
        }
    }

    void displayDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    map<int, BankAccount> accounts;
    int choice, accNo;
    string name;
    double amount;

    while (true) {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Account Details\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Deposit Amount: ";
            cin >> amount;
            accounts[accNo] = BankAccount(name, accNo, amount);
            cout << "Account created successfully!\n";
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                accounts[accNo].deposit(amount);
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                accounts[accNo].withdraw(amount);
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                accounts[accNo].displayDetails();
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 5:
            cout << "Thank you for using the Bank Management System. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
