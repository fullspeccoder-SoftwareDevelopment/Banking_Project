/*
______________
    Bank Project      
    Version 0.2 
______________
*/

#include <iostream>
#include <vector>
#include "/Users/jcbwlsn/Downloads/Coding/CPP/Banking Project/headers/accounts.hpp"
#include "/Users/jcbwlsn/Downloads/Coding/CPP/Banking Project/headers/menus.hpp"

using namespace std;

void menu(ManageAccounts& t_strAccounts);

int main()
{
    CheckingAccount sampleAccount("Sample");
    ManageAccounts strAccounts;
    strAccounts.addAccount("Sample", 0, "Checking");
    menu(strAccounts);
    return 0;
}

void menu(ManageAccounts& t_strAccounts)
{
    Account* selectedAccount = &t_strAccounts.getAccounts()[0];
    PrintAccounts print;
    TransactionMenu tm;
    EditorMenu em;
    cout << "\n======================" << endl;
    cout << "\nWelcome to the Bank!!!\n";
    cout << "\n======================\n" << endl;

    int choice = 0;
    string type = "";
    string name = "";
    int deposit = 0;
    while(choice != 7)
    {

        if(selectedAccount->getName() != "Sample" && selectedAccount->getID() != 2475278)
        {
            cout << "\tSelected Account - " << selectedAccount->getName() << " | ID: " << selectedAccount->getID() << endl;
        }
        
        cout << "\n1 - Create Account\n2 - Select Account\n3 - Transaction Menu\n4 - Edit Menu" 
        << "\n5 - Print Selected Account\n6 - View All Available Accounts\n7 - Quit\n";
        cin >> choice;

        switch(choice)
        {
            // Create an account
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
            // Select Account
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
                    cout << "\nAccount Found!!!\n" << endl;
                }
                break;
            // Transaction Menu
            case 3:
                cout << "\nTransaction Menu Initializing..." << endl;
                tm.showMenu(*selectedAccount);
                break;
            // Edit Menu
            case 4:
                cout << "\nEdit Menu Initializing..." << endl;
                em.showMenu(*selectedAccount);
                break;
            // Print Selected Account
            case 5:
                if(selectedAccount->getName() == "Sample")
                {
                    cout << "\nNot found" << endl;
                }
                else
                {
                    print.printAccountInfo(*selectedAccount);
                }
                break;
            // Print All Accounts
            case 6:
                print.printAllAccounts(t_strAccounts.getAccounts());
                break;
            // Quits Application
            case 7:
                cout << "\nQuitting Application...\n" << endl;
                break;
        }
    }
}