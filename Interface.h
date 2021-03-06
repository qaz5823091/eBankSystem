#ifndef INTERFACE_H
#define INTERFACE_H

#include "Profile.h"
#include <iostream>
#include <string>
using namespace std;

class Interface {
    private:
        string command;
        Profile profile;

    public:
        Interface();
        void login();
        void signUp();
        void logout();
        void deposit(double money);
        void withdraw(double money);
        void display();

};

#endif // INTERFACE_H
