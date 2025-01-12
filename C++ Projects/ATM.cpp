#include <iostream>
#include <string>
#include <iomanip> // For formatted output

using namespace std;

// Function prototypes
void displayMenu();
void checkBalance(double balance);
void deposit(double &balance);
void withdraw(double &balance);
bool authenticate(const string &password);

// Main function
int main() {
    string correctPassword = "1234"; // Default password
    string inputPassword;
    double balance = 1000.0; // Initial balance
    int attempts = 3;

    cout << "==============================\n";
    cout << "      Welcome to ATM System   \n";
    cout << "==============================\n";

    // Password validation
    while (attempts > 0) {
        cout << "Enter your password: ";
        cin >> inputPassword;

        if (authenticate(inputPassword)) {
            cout << "Authentication successful!\n\n";
            break;
        } else {
            attempts--;
            cout << "Incorrect password. Attempts left: " << attempts << "\n";
        }

        if (attempts == 0) {
            cout << "Too many failed attempts. Exiting...\n";
            return 0;
        }
    }

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\n========= ATM Menu =========\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "============================\n";
}

// Function to check the balance
void checkBalance(double balance) {
    cout << fixed << setprecision(2); // Set precision for money
    cout << "Your current balance is: $" << balance << "\n";
}

// Function to deposit money
void deposit(double &balance) {
    double amount;
    cout << "Enter the amount to deposit: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid deposit amount. Please try again.\n";
    } else {
        balance += amount;
        cout << "Deposit successful! Your new balance is: $" << balance << "\n";
    }
}

// Function to withdraw money
void withdraw(double &balance) {
    double amount;
    cout << "Enter the amount to withdraw: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid withdrawal amount. Please try again.\n";
    } else if (amount > balance) {
        cout << "Insufficient funds. Please try again.\n";
    } else {
        balance -= amount;
        cout << "Withdrawal successful! Your new balance is: $" << balance << "\n";
    }
}

// Function to authenticate user
bool authenticate(const string &password) {
    return password == "1234";
}
