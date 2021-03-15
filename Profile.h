#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;

class Profile {
    private:
        string account;
        string password;
        double balance;
        double interest;
        int not_update_times;
        int tried_times;
        bool locked;

    public:
        Profile(string act, string pwd, double bal, char loc);
        string getAccount();
        string getPassword();
        double getBalance();
        double getInterest();
        int getNotUpdateTimes();
        int getTriedTimes();
		bool getLocked();

		void setTriedTimes(int times);
        void setLocked(bool isLocked);
        //void setInfo(string act, string pwd);
        //void setInfo(string act, string pwd, double bal, double inte, int nut, int tt, bool loc);
        void deposit(double money);
        void withdraw(double money);
        void print();
};

#endif // PROFILE_H
