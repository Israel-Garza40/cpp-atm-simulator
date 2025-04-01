#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void displayMenu();
bool authenticate(int pin);
double checkBalance(double balance);
void deposit(double &balance, double amount, vector<string> &history);
void withdraw(double &balance, double amount, vector<string> &history, double &dailyLimit);
void showHistory(const vector<string> &history);

int main()
{
    const int PIN = 1234; // Predefined PIN
    double balance = 1000.0; // Initial balance
    double dailyLimit = 500.0; // Daily withdrawal limit
    vector<string> history; // Transaction history
    int pin, choice;
    
    cout << "Enter your PIN: ";
    cin >> pin;
    
    if (!authenticate(pin)) {
        cout << "Incorrect PIN. Exiting..." << endl;
        return 1;
    }
    
    do {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Your balance: $" << checkBalance(balance) << endl;
                break;
            case 2:
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                deposit(balance, depositAmount, history);
                break;
            case 3:
                double withdrawAmount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                withdraw(balance, withdrawAmount, history, dailyLimit);
                break;
            case 4:
                showHistory(history);
                break;
            case 5:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}

// Function Definitions
void displayMenu() {
    cout << "\nATM Menu:" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transaction History" << endl;
    cout << "5. Exit" << endl;
}

bool authenticate(int pin) {
    const int correctPIN = 1234;
    return pin == correctPIN;
}

double checkBalance(double balance) {
    return balance;
}

void deposit(double &balance, double amount, vector<string> &history) {
    if (amount > 0) {
        balance += amount;
        history.push_back("Deposited: $" + to_string(amount));
        cout << "Deposit successful. New balance: $" << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

void withdraw(double &balance, double amount, vector<string> &history, double &dailyLimit) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
    } else if (amount > balance) {
        cout << "Insufficient balance." << endl;
    } else if (amount > dailyLimit) {
        cout << "Exceeded daily withdrawal limit." << endl;
    } else {
        balance -= amount;
        dailyLimit -= amount;
        history.push_back("Withdrawn: $" + to_string(amount));
        cout << "Withdrawal successful. New balance: $" << balance << endl;
    }
}

void showHistory(const vector<string> &history) {
    cout << "\nTransaction History:" << endl;
    if (history.empty()) {
        cout << "No transactions yet." << endl;
    } else {
        for (const string &record : history) {
            cout << record << endl;
        }
    }
}