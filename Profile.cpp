#include "Profile.h"

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double ANNUAL_RATE = 0.008;

// new an account
Profile::Profile(string act, string pwd, double bal, char loc) {
	bool isLocked;
	if (loc == 'Y')
		locked = true;
	else
		locked = false;

	account = act;
	password = pwd;
	balance = bal;
	interest = 0;
	not_update_times = 0;
	tried_times = 0;
}

string Profile::getAccount() {
    return account;
}

string Profile::getPassword() {
    return password;
}

double Profile::getBalance() {
    return balance;
}

double Profile::getInterest() {
    return interest;
}

int Profile::getNotUpdateTimes() {
    return not_update_times;
}

int Profile::getTriedTimes() {
    return tried_times;
}

bool Profile::getLocked() {
	return locked;
}

void Profile::setTriedTimes(int times) {
    tried_times = times;
}

/*
void Profile::setInfo(string act, string pwd) {
    account = act;
    password = pwd;
    balance = 0.0;
    interest = 0.0;
    not_update_times = 0;
    tried_times = 0;
    locked = false;
}

void Profile::setInfo(string act, string pwd, double bal, double inte,
    int nut, int tt, bool loc) {
    account = act;
    password = pwd;
    balance = bal;
    interest = inte;
    not_update_times = nut;
    tried_times = tt;
    locked = loc;
}*/

void Profile::deposit(double money) {
    balance += money;
    cout<<fixed<<setprecision(2)<<"Deposit "<<money<<" dollars"<<endl;
}

void Profile::withdraw(double money) {
    if (money > balance) {
        cout<<"Insufficient balance"<<endl;
        return ;
    }

    balance -= money;
    cout<<fixed<<setprecision(2)<<"Withdraw "<<money<<" dollars"<<endl;
}

void Profile::print() {
    cout<<"=================================="<<endl;
    cout<<"Account:  "<<account<<endl;
    cout<<"Password: "<<password<<endl;
    cout<<fixed<<setprecision(2)<<"Deposit:  "<<balance<<endl;
    cout<<fixed<<setprecision(2)<<"Interest: "<<interest<<endl;
    cout<<"Locked:   "<<locked<<endl;
    cout<<"=================================="<<endl;
}
