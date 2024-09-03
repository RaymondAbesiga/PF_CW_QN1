#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Account {
    string password;
    double balance;
};

int main() {
    map<string, Account> accounts;
    string userId, password;
    char choice;

    while (true) {
        cout << "Hi! Welcome to the ATM Machine!" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "l -> Login" << endl;
        cout << "c -> Create New Account" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";
        cin >> choice;

        if (choice == 'q') {
            cout << "Goodbye!" << endl;
            break;
        } else if (choice == 'c') {
            cout << "Please enter your user id: ";
            cin >> userId;
            cout << "Please enter your password: ";
            cin >> password;
            accounts[userId] = {password, 0.0};
            cout << "Thank You! Your account has been created!" << endl;
        } else if (choice == 'l') {
            cout << "Please enter your user id: ";
            cin >> userId;
            cout << "Please enter your password: ";
            cin >> password;

            if (accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
                cout << "Access Granted!" << endl;
                char mainChoice;
                while (true) {
                    cout << "d -> Deposit Money" << endl;
                    cout << "w -> Withdraw Money" << endl;
                    cout << "r -> Request Balance" << endl;
                    cout << "q -> Quit" << endl;
                    cout << "> ";
                    cin >> mainChoice;

                    if (mainChoice == 'q') {
                        break;
                    } else if (mainChoice == 'd') {
                        double depositAmount;
                        cout << "Amount of deposit: $";
                        cin >> depositAmount;
                        accounts[userId].balance += depositAmount;
                    } else if (mainChoice == 'w') {
                        double withdrawAmount;
                        cout << "Amount of withdrawal: $";
                        cin >> withdrawAmount;
                        if (withdrawAmount <= accounts[userId].balance) {
                            accounts[userId].balance -= withdrawAmount;
                        } else {
                            cout << "Insufficient balance!" << endl;
                        }
                    } else if (mainChoice == 'r') {
                        cout << "Your balance is $" << accounts[userId].balance << "." << endl;
                    } else {
                        cout << "Invalid option!" << endl;
                    }
                }
            } else {
                cout << "*** LOGIN FAILED! ***" << endl;
            }
        } else {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}
