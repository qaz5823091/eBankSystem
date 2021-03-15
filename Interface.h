#ifndef INTERFACE_H
#define INTERFACE_H

#include "Profile.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Interface {
    private:
        string command;
		int index;
        vector<Profile> profile;

    public:
        Interface();
		~Interface();
		void load();
		void dump();

        void login();
        void signUp();
        void logout();
        void deposit(int index, double money);
        void withdraw(int index, double money);
        void display(int index);

};

#endif // INTERFACE_H
