#include "Interface.h"
#include "Profile.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int totalTryTimes = 3;
const int tradeTimes = 3;

Interface::Interface() {
	load();
	
	cout<<"=============================="<<endl;
	cout<<"login or signup"<<endl;
	cout<<"Command > ";
	cin>>command;

	if (command == "login")
		login();
	else if (command == "signup")
		signUp();
	else if (command == "exit")
		return ;
	else
		cout<<"Unknown command!"<<endl;
}

Interface::~Interface(){
	//dump();
}

void Interface::load() {
	fstream fileIn;
	fileIn.open("userFile.txt");
	
	string act, pwd;
	double bal;
	char loc;
	while (fileIn>>act>>pwd>>bal>>loc) {
		profile.push_back( Profile(act, pwd, bal, loc) );
	}
	
	fileIn.close();
}

void Interface::dump() {
	fstream fileOut;
	fileOut.open("userFile.txt");
	// fileOut == cout
	
	for (int i=0;i<profile.size();i++) {
		char isLocked;
		if (profile[i].getLocked())
			isLocked = 'Y';
		else
			isLocked = 'N';

		fileOut<<profile[i].getAccount()<<" "<<profile[i].getPassword()<<" "<<profile[i].getBalance()<<" "<<isLocked<<endl;
	}

	fileOut.close();
}

void Interface::login() {
    string account, password;

    cout<<"Account: ";
    cin>>account;

    // file in
	bool isLogin = false;
	for (int i=0;i<profile.size();i++) {
		if ( account == profile[i].getAccount() ) {
			index = i;

			if ( profile[i].getLocked() ) {
				isLogin = false;
				break;
			}

			for (int tryTimes = 1;tryTimes <= totalTryTimes;tryTimes++) {
				cout<<"Password: ";
				cin>>password;
				if ( password == profile[i].getPassword() ) {
					isLogin = true;
					break;
				}
				else {
					profile[i].setTriedTimes(tryTimes);
					cout<<"You have "<<totalTryTimes-tryTimes<<" tried times !"<<endl;
				}
			}

			break;
		}
	}

	if ( isLogin == false && profile[index].getTriedTimes() == totalTryTimes ) {
		cout<<"Login failed, Try again"<<endl;
		return ;
	}
    
	

    while (1) {
		cout<<"=============================="<<endl;
		cout<<"Function : deposit, withdraw, display"<<endl;
        cout<<"Command > ";
		cin>>command;

		if(profile[index].getNotUpdateTimes()>=tradeTimes){
			profile[index].setLocked(true);
		}

		double money;

		if ( profile[index].getLocked() ) {
			display(index);
			cout<<endl<<"You've been locked out"<<endl;
			logout();
			break;
		}
        else if (command == "logout") {
            logout();
			break;
        }
        else if (command == "deposit") {
            cin>>money;
            deposit(index, money);
        }
        else if (command == "withdraw") {
            cin>>money;
            withdraw(index, money);
        }
        else if (command == "display") {
            display(index);
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

	bool isSigned = false;
	for (int i=0;i<profile.size();i++) {
		if ( account == profile[i].getAccount() ) {
			isSigned = true;
			break;
		}
	}

	if (isSigned)
		cout<<"The account is being used"<<endl;
	else {
		cout<<"Your password: ";
		cin>>tempPassword;
		cout<<"Password again: ";
		cin>>password;

		if (password == tempPassword) {
			cout<<endl<<"Sign successfully!"<<endl;
			cout<<"Please login with new account."<<endl;
			profile.push_back( Profile(account, password, 0, 'N') );
			dump();
		}
		else {
			cout<<endl<<"Sign up failed..."<<endl;
			cout<<"Please sign up again!"<<endl;
		}
	}

    return ;
}

void Interface::logout() {
	profile[index].setLocked(false);
    // file out
	dump();
    cout<<"Bye bye!"<<endl;

    return ;
}

void Interface::deposit(int index, double money) {
    profile[index].deposit(money);
}

void Interface::withdraw(int index, double money) {
    profile[index].withdraw(money);
}

void Interface::display(int index) {
    profile[index].print();
}
