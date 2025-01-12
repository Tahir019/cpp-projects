#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Account {
private:
    string accNo;
    string name;
    double balance;

public:
    // Default constructor
    Account() : accNo(""), name(""), balance(0.0) {}

    // Parameterized constructor
    Account(string accNo, string name, double initialBalance)
        : accNo(accNo), name(name), balance(initialBalance) {}

    // Deposit money into the account
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be greater than 0." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << " into account " << accNo << endl;
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds in account " << accNo << endl;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be greater than 0." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << " from account " << accNo << endl;
        }
    }

    // Display account details
    void display() const {
        cout << "Account No: " << accNo << ", Name: " << name
             << ", Balance: " << balance << endl;
    }

    // Get account balance
    double getBalance() const {
        return balance;
    }

    // Transfer money to another account
    bool transfer(Account &toAccount, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds to transfer from account " << accNo << endl;
            return false;
        } else if (amount <= 0) {
            cout << "Transfer amount must be greater than 0." << endl;
            return false;
        } else {
            balance -= amount;
            toAccount.deposit(amount);
            cout << "Transferred: " << amount << " from account " << accNo
                 << " to account " << toAccount.accNo << endl;
            return true;
        }
    }
};

int main() {
    unordered_map<string, Account> accounts;

    while (true) {
        cout << "\n=== Online Banking System ===\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting the system. Goodbye!\n";
            break;
        }

        string accNo;
        switch (choice) {
        case 1: {
            cout << "Enter Account Number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                cout << "Account with this number already exists.\n";
                break;
            }

            cout << "Enter Account Holder Name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            double initialBalance;
            cin >> initialBalance;

            accounts[accNo] = Account(accNo, name, initialBalance);
            cout << "Account created successfully.\n";
            break;
        }

        case 2: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (accounts.find(accNo) == accounts.end()) {
                cout << "Account not found.\n";
                break;
            }

            cout << "Enter Amount to Deposit: ";
            double amount;
            cin >> amount;

            accounts[accNo].deposit(amount);
            break;
        }

        case 3: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (accounts.find(accNo) == accounts.end()) {
                cout << "Account not found.\n";
                break;
            }

            cout << "Enter Amount to Withdraw: ";
            double amount;
            cin >> amount;

            accounts[accNo].withdraw(amount);
            break;
        }

        case 4: {
            cout << "Enter Your Account Number: ";
            string fromAccNo;
            cin >> fromAccNo;

            if (accounts.find(fromAccNo) == accounts.end()) {
                cout << "Your account not found.\n";
                break;
            }

            cout << "Enter Receiver Account Number: ";
            string toAccNo;
            cin >> toAccNo;

            if (accounts.find(toAccNo) == accounts.end()) {
                cout << "Receiver account not found.\n";
                break;
            }

            cout << "Enter Amount to Transfer: ";
            double amount;
            cin >> amount;

            accounts[fromAccNo].transfer(accounts[toAccNo], amount);
            break;
        }

        case 5: {
            cout << "Enter Account Number: ";
            cin >> accNo;

            if (accounts.find(accNo) == accounts.end()) {
                cout << "Account not found.\n";
                break;
            }

            accounts[accNo].display();
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
