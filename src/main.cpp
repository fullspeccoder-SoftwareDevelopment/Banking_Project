/*
______________
    Bank Project      
    Version 0.2 
______________
*/

#include <iostream>
#include <vector>
#include "/Users/jcbwlsn/Downloads/Coding/CPP/Banking Project/headers/accounts.hpp"

using namespace std;

void menu(StoreAccounts& t_strAccounts);

int main()
{
    CheckingAccount sampleAccount("Sample");
    StoreAccounts strAccounts;
    strAccounts.addAccount("Sample", 0, "Checking");
    menu(strAccounts);
    return 0;
}

void menu(StoreAccounts& t_strAccounts)
{
    Account* selectedAccount = &t_strAccounts.getAccounts()[0];
    PrintAccounts print;
    cout << "\nWelcome to the Bank!!!" << endl;

    int choice = 0;
    string type = "";
    string name = "";
    int deposit = 0;
    while(choice != 5)
    {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1 - Create Account\t2 - Find Account\n3 - View All Available Accounts\t4 - Print Selected Account\n5 - Quit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nWhat kind of account would you like to open today?\nChecking\tSavings" << endl;
                cin >> type;
                cout << "\nWhat would you like to name this account?" << endl;
                cin >> name;
                cout <<"\nWould you like to put anything in this account today?" << endl;
                cin >> deposit;
                t_strAccounts.addAccount(name, deposit, type);
                cout << "\nAccount added!!!" << endl;
                print.printAccountInfo(t_strAccounts.getAccounts().back());
                break;
            case 2:
                cout << "Enter ID" << endl;
                cin >> choice;
                selectedAccount = &t_strAccounts.findAccount(choice);
                if(selectedAccount->getName() == "Sample")
                {
                    cout << "\nNot found" << endl;
                }
                else
                {
                    cout << "\nAccount Found!!!" << endl;
                }
                break;
            case 3:
                print.printAllAccounts(t_strAccounts.getAccounts());
                break;
            case 4:
                if(selectedAccount->getName() == "Sample")
                {
                    cout << "\nNot found" << endl;
                }
                else
                {
                    print.printAccountInfo(*selectedAccount);
                }
                break;
            case 5:
                cout << "\nQuitting Application...\n" << endl;
                break;
        }
    }
}