#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "/Users/jcbwlsn/Downloads/Coding/CPP/Banking Project/headers/accounts.hpp"

using namespace std;

void menu();

int main()
{
    // Account account1(0, "Jake");
    // RecieptHistory history;

    // account1.setMoney(5);
    // account1.setDescription("Super Market");
    // history.pushState(account1.createAccountState());
    // account1.setMoney(10);
    // account1.setDescription("Walmart");
    // history.pushState(account1.createAccountState());
    // account1.setMoney(15);
    // account1.setDescription("Gas");

    // cout << account1.getNameOfAccount() << "'s Account History: \n" << endl;
    // history.printHistory();
    menu();
    return 0;
}

void menu()
{
    Bank bank;
    int choice = 0;
    string name = "";
    cout << "What would you like to do today?" << endl;
    cout << "\n1 - Create Account\t2 - Quit\n\n";
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "What would you like the name to be?";
            cin >> name;
            bank.pushAccount(name);
            break;
        case 2:
            break;
    }
    bank.getAccount(name).setDescription("Jake's Account");
    cout << bank.getAccount(name).getDescription()<< endl;
}