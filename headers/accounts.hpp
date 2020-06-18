#ifndef ACCOUNTS__HPP_
#define ACCOUNTS__HPP_

#include <iostream>
#include <vector>

using namespace std;

class Account
{
    protected:
        long int m_balance;
        string m_nameOfAccount;
    public:
        Account(string t_name="Person", long int t_amount=0)
        : m_nameOfAccount(t_name) ,m_balance(t_amount){}
        long int getBalance()
        {
            return m_money;
        }
        string getName()
        {
            return m_nameOfAccount;
        }
};

class CheckingAccount : public Account
{
    public:
        CheckingAccount(string t_name, long int t_amount=0)
        {
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class SavingsAccount : public Account
{
    public:
        SavingsAccount(string t_name, long int t_amount=0)
        {
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class Print
{
    public:
        void printAccountInfo(Account& t_account)
        {
            cout << "\n\t\t\t" << t_account.getName() << "'s Account\n" << endl;
            cout << "\t\t\t\t\tAccount Balance: " << t_account.getBalance() << "\n" << endl;
        }
        void printName(Account& t_account)
        {
            cout << "\n" << t_account.getName() << endl;
        }
        void printBalance(Account& t_account)
        {
            cout << "\n" << t_account.getBalance() << endl;
        }
};

class StoreAccounts
{
    private:
        std::vector<Account> m_accounts;
        Print m_printer;
    public:
        StoreAccounts(vector<Account>& t_accounts)
        : m_accounts(t_accounts){}
        void printAllAccounts()
        {
            cout << "\nAll Stored Accounts" << endl;
            for(int i = 0; i < m_accounts.size(); i++)
            {
                m_printer.printName(m_accounts[i]);
            }
            cout << "\nEnd of all accounts in system\n" << endl;
        }
        Account getAccount()
        {
            return m_accounts[0];
        }
        Print getPrinter()
        {
            return m_printer;
        }
};

#endif