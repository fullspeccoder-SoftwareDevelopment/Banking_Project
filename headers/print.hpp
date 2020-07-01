#ifndef __PRINT__HPP_
#define __PRINT__HPP_

#include <iostream>
#include <iomanip>
#include <vector>
#include "accounts.hpp"

using namespace std;

class PrintAccounts
{
    private:
        void printName(I_Account& t_account)
        {
            cout << "\nName Of Account: \n\t" << t_account.getName() << endl;
        }
        void printBalance(I_Account& t_account)
        {
            cout << "\nBalance: \n\t" << t_account.getBalance() << endl;
        }
        void printID(I_Account& t_account)
        {
            cout << "\nAccount ID: \n\t" << t_account.getID() << endl;
        }
        void printPhoneNumber(I_Account& t_account)
        {
            cout << "\nPhone Number: \n\t";
            cout <<  t_account.getContacts()->getItem(1) << endl;
        }
        void printWorkNumber(I_Account& t_account)
        {
            cout << "\nWork Number: \n\t";
            cout << t_account.getContacts()->getItem(2) << endl;
        }
        void printContactInfo(I_Account& t_account)
        {
            cout << "\nContact Information: " << endl;
            for(int i = 3; i < 7; i++)
            {
                cout << "\t" << t_account.getContacts()->getItem(i) << endl;
            }
        }
    public:
        void printAccountInfo(I_Account& t_account)
        {
            system("clear");
            cout << "\tCurrent Account Info: " << endl;
            this->printName(t_account);
            this->printBalance(t_account);
            this->printID(t_account);
            this->printPhoneNumber(t_account);
            this->printWorkNumber(t_account);
            this->printContactInfo(t_account);
        }
        void printAllAccounts(vector<Account>& t_accounts)
        {
            system("clear");
            cout <<"\t All Stored Accounts" << endl;
            cout << "\t" << setw(21) << left << setfill('-') << " ";
            for(int i = 0; i < t_accounts.size(); i++)
            {
                cout << setfill(' ');
                if(t_accounts[i].getType() == "Checking" || t_accounts[i].getType() == "Savings")
                {
                this->printName(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                this->printID(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                cout << setw(28) << left << setfill('-');
                cout << "\n" << setfill(' ');
                }
            }
        }
};

#endif