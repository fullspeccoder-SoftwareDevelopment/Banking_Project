#ifndef MENUS__HPP_
#define MENUS__HPP_

#include <iostream>
#include "accounts.hpp"

using namespace std;

class TransactionMenu
{
    private:
        void withdraw(Account& t_account)
        {
            int choice = 0;
            cout << "\nHow much would you like to Withdraw today?" << endl;
            cin >> choice;
            if(choice > 0 && t_account.getBalance() > 0 && t_account.getBalance() > choice)
            {
            t_account.setBalance(t_account.getBalance() - choice);
            }
            else
            {
                cout << "Don't Have Enough Funds in Account!!" << endl;
            }
        }
        void deposit(Account& t_account)
        {
            int choice = 0;
            cout << "\nHow much would you like to Deposit today?" << endl;
            cin >> choice;
            if(choice >= 0)
            {
            t_account.setBalance(t_account.getBalance() + choice);
            }
            else
            {
                cout << "Don't Have Enough Funds in Account!!" << endl;
            }
        }
        void checkBalance(Account& t_account)
        {
            cout << "Available Balance: " << t_account.getBalance() << endl;
        }

    public:
        void showMenu(Account& t_account)
        {
            int anotherTransaction = 1;
            while(anotherTransaction == 1)
            {
                int choice = 0;
                cout << "\nWelcome to the Transaction Menu!\n" << endl;
                cout << "1 - Withdraw\t2 - Deposit\t3 - Check Balance\n" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        this->withdraw(t_account);
                        break;
                    case 2:
                        this->deposit(t_account);
                        break;
                    case 3:
                        this->checkBalance(t_account);
                        break;
                }
                cout << "\nWould you like to start another Transaction?" << endl;
                cout <<"1 - Yes\t2 - No" << endl;
                cin >> anotherTransaction;
            }

        }
};

class AddressMenu
{
    private:
        int counter = 0;
        string addressDetail(string &t_detail)
        {
            vector<string> detailNames{"Street Address", "City", "State", "Zip Code"};
            cout << "Enter " << detailNames[counter] << ": " << endl;
            getline(cin, t_detail);
            cout << "" << endl;
            return t_detail;
        }
    public:
        void showMenu(Account& t_account)
        {
            string detail{};
            getline(cin, detail);
            cout << "Change in the following order: \n" << endl;
            switch(1)
            {
                case 1:
                    this->addressDetail(detail);
                    t_account.getContacts()->setItem(detail, 3);
                    counter++;
                case 2:
                    this->addressDetail(detail);
                    t_account.getContacts()->setItem(detail, 4);
                    counter++;
                case 3:
                    this->addressDetail(detail);
                    t_account.getContacts()->setItem(detail, 5);
                    counter++;
                case 4:
                    this->addressDetail(detail);
                    t_account.getContacts()->setItem(detail, 6);
                    counter++;
            }
            counter = 0;
        }
};

class EditorMenu
{
    private:
        AddressMenu am;
        string phoneNumber(string &t_detail)
        {
            cout << "\nEnter Phone Number: " << endl;
            cin >> t_detail;
            cout << "" << endl;
            return t_detail;
        }
        string workNumber(string &t_detail)
        {
            cout << "\nEnter Work Number: " << endl;
            cin >> t_detail;
            cout << "" << endl;
            return t_detail;
        }
        void Option3()
        {
            cout << "\nEmergency Contact Info" << endl;
        }
        void Option4(Account& t_account)
        {
            am.showMenu(t_account);
        }
        string Option5(ManageAccounts& t_accounts)
        {
            string choice = "";
            cout << "\nAre you sure?" << endl;
            cin >> choice;
            if(choice == "yes")
            {
                t_accounts.deleteAccount();
            }
            return choice;
        }
    public:
        int showMenu(Account& t_account, ManageAccounts& t_accounts)
        {
            int choice = 0;
            string detail = "";
            getline(cin, detail);
            while(choice != 6 && choice != 5)
            {
                cout << "\nWelcome to the Editor Menu!" << endl;
                cout << "1 - Update Phone No.\t2 - Update Work No.\n"
                << "3 - Update Emergency Info\t4 - Update Address (Menu)\n"
                << "5 - Close Account\t6 - Exit" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        this->phoneNumber(detail);
                        t_account.getContacts()->setItem(detail, 1);
                        break;
                    case 2:
                        this->workNumber(detail);
                        t_account.getContacts()->setItem(detail, 2);
                        break;
                    case 3:
                        this->Option3();
                        break;
                    case 4:
                        this->Option4(t_account);
                        break;
                    case 5:
                        if(this->Option5(t_accounts) == "yes")
                        {
                            choice = 6;
                        }
                        break;
                }
            }
            return choice;
        }
};

#endif