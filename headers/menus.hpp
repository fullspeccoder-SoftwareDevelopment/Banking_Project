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
        void Option1()
        {
            cout << "Changing House Number..." << endl;
        }
        void Option2()
        {
            cout << "Changing Street..." << endl;
        }
        void Option3()
        {
            cout << "Changing City..." << endl;
        }
        void Option4()
        {
            cout << "Changing State..." << endl;
        }
        void Option5()
        {
            cout << "Changing Zip Code..." << endl;
        }
    public:
        void showMenu(Account& t_account)
        {
            cout << "Change in the following order: \nHouse Street\nCity, State\nZip Code" << endl;
            switch(1)
            {
                case 1:
                    this->Option1();
                case 2:
                    this->Option2();
                case 3:
                    this->Option3();
                case 4:
                    this->Option4();
                case 5:
                    this->Option5();
            }
        }
};

class EditorMenu
{
    private:
        AddressMenu am;
        void Option1()
        {
            cout << "\nChanging Phone Number..." << endl;
        }
        void Option2()
        {
            cout << "\nChanging Work Phone Number..." << endl;
        }
        void Option3()
        {
            cout << "\nChanging Emergency Contact Info..." << endl;
        }
        void Option4(Account& t_account)
        {
            am.showMenu(t_account);
        }
        void Option5(Account& t_account)
        {
            string choice = "";
            cout << "\nAre you sure?" << endl;
            cin >> choice;
            if(choice == "yes")
            {
                cout << "\nDeleting Account..." << endl;
            }
        }
    public:
        void showMenu(Account& t_account)
        {
            int choice = 0;
            while(choice != 6)
            {
                cout << "\nWelcome to the Editor Menu!" << endl;
                cout << "1 - Update Phone No.\t2 - Update Work No.\n"
                << "3 - Update Emergency Info\t4 - Update Address (Menu)\n"
                << "5 - Delete Account\t6 - Quit" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        this->Option1();
                        break;
                    case 2:
                        this->Option2();
                        break;
                    case 3:
                        this->Option3();
                        break;
                    case 4:
                        this->Option4(t_account);
                        break;
                    case 5:
                        this->Option5(t_account);
                        break;
                }
            }
        }
};

#endif