#include "Interface.h"
#include "Profile.h"

#include <iostream>
using namespace std;

Interface::Interface() {
    cout<<"Command > ";
    cin>>command;

    if (command == "login")
        login();
    else if (command == "signup")
        signUp();
    else
        cout<<"Unknown command!"<<endl;
}

void Interface::login() {
    string account, password;

    cout<<"Account: ";
    cin>>account;
    cout<<"Password: ";
    cin>>password;

    // file in
    if (account == "abc" && password == "123")
        cout<<"login successfully!"<<endl;
    else {
        cout<<"login failed..."<<endl;
        return ;
    }

    // file in
    profile.setInfo(account, password, 1000.0, 100.0,
        0, 0, false);

    while (1) {
        cout<<"Command > ";
        cin>>command;

        double money;

        if (command == "logout") {
            logout();
            break;
        }
        else if (command == "deposit") {
            cin>>money;
            deposit(money);
        }
        else if (command == "withdraw") {
            cin>>money;
            withdraw(money);
        }
        else if (command == "display") {
            display();
        }
        else {
            cout<<"Unknown command!"<<endl;
        }

    }
}

void Interface::signUp() {
    string account, password, tempPassword;

    cout<<"Your account: ";
    cin>>account;
    cout<<"Your password: ";
    cin>>tempPassword;
    cout<<"Password again: ";
    cin>>password;

    if (password == tempPassword) {
        cout<<endl<<"Sign successfully!"<<endl;
        cout<<"Please login with new account."<<endl;
    }
    else {
        cout<<endl<<"Sign up failed..."<<endl;
        cout<<"Please sign up again!"<<endl;
    }

    return ;
}

void Interface::logout() {
    // file out
    cout<<"Bye bye!"<<endl;

    return ;
}

void Interface::deposit(double money) {
    profile.deposit(money);
}

void Interface::withdraw(double money) {
    profile.withdraw(money);
}

void Interface::display() {
    profile.print();
}
