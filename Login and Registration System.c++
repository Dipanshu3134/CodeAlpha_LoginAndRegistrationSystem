#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int choice;
    cout << "\t\t\t_____________________________________________\n";
    cout << "\t\t\t          Welcome to the Login Page          \n";
    cout << "\t\t\t_____________________________________________\n\n";
    cout << "\t\t\t_______________      MENU     _______________\n\n";
    cout << "\t Press 1 to LOGIN\n";
    cout << "\t Press 2 to REGISTER\n";
    cout << "\t Press 3 if you FORGOT PASSWORD\n";
    cout << "\t Press 4 to EXIT\n";
    cout << "\n\t Please enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "\t\t\t Thank you! \n\n";
            break;
        default:
            cout << "\t\t\t Invalid choice! Please select an option from the menu.\n";
            main();
    }
    return 0;
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");

    cout << "\t\t\t Please enter your username and password: \n";
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\n Your login was successful! \n Thanks for logging in.\n";
    } else {
        cout << "\n LOGIN ERROR!! \n Please check your username and password.\n";
    }
    main();
}

void registration() {
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\t Enter a username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter a password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");

    cout << "\n\t\t\t Registration successful! \n";
    main();
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t Forgot your password? No worries! \n";
    cout << "\t\t\t Press 1 to search your ID by username\n";
    cout << "\t\t\t Press 2 to go back to the main menu\n";
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter the username you remember: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Your account has been found! \n";
                cout << "\n\n Your password is: " << spass << endl;
            } else {
                cout << "\n\t Sorry, your account was not found.\n";
            }
            main();
            break;
        }
        case 2:
            main();
            break;
        default:
            cout << "\t\t\t Invalid choice! Please try again.\n";
            forgot();
    }
}
