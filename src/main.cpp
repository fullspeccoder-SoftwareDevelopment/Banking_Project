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
    Account acc1("Jake", 500);
    Account acc2("Jeff");
    Account acc3("Ryan", 250);
    CheckingAccount chckAccount("Jake");
    vector<Account> accounts{acc1, acc2, acc3, chckAccount};
    StoreAccounts strAccounts(accounts);
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
        cout << "1 - View Balance\t2 - View Available Accounts\t3 - Quit\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nBalance Amount" << endl;
                break;
            case 2:
                t_strAccounts.printAllAccounts();
                break;
            case 3:
                cout << "\nQuitting Application..." << endl;
                break;
        }
    }
}