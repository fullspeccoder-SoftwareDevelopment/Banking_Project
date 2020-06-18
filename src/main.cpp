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
    SavingsAccount acc1("Jake", 500);
    CheckingAccount acc2("Jeff");
    SavingsAccount acc3("Ryan", 250);
    CheckingAccount chckAccount("Jake");
    StoreAccounts strAccounts;
    menu(strAccounts);
    return 0;
}

void menu(StoreAccounts& t_strAccounts)
{
    cout << "\nWelcome to the Bank!!!" << endl;

    int choice = 0;
    while(choice != 3)
    {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1 - Create Account\t2 - View Available Accounts\t3 - Quit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                t_strAccounts.addAccount("Jake", 0, "Checking");
                break;
            case 2:
                t_strAccounts.getPrinter().printAllAccounts(t_strAccounts.getAccounts());
                break;
            case 3:
                cout << "\nQuitting Application..." << endl;
                break;
        }
    }
}