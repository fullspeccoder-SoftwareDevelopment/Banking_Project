#ifndef ACCOUNTS__HPP_
#define ACCOUNTS__HPP_

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Account
{
    protected:
        long int m_balance;
        string m_nameOfAccount;
        const long int m_ID = rand() % 9999999 + 1;
    public:
        long int& getBalance()
        {
            return m_balance;
        }
        string& getName()
        {
            return m_nameOfAccount;
        }
        long int getID()
        {
            return m_ID;
        }
};

class CheckingAccount : public Account
{
    private:
        const string m_type = "Checking";
    public:
        CheckingAccount(string t_name, long int t_amount=0)
        {
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class SavingsAccount : public Account
{
    private:
        const string m_type = "Savings";
    public:
        SavingsAccount(string t_name, long int t_amount=0)
        {
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class PrintAccounts
{
    public:
        void printAccountInfo(Account& t_account)
        {
            this->printName(t_account);
            this->printBalance(t_account);
            this->printID(t_account);
        }
        void printName(Account& t_account)
        {
            cout << "\nName Of Account: " << t_account.getName() << endl;
        }
        void printBalance(Account& t_account)
        {
            cout << "\nBalance: " << t_account.getBalance() << endl;
        }
        void printID(Account& t_account)
        {
            cout << "\nAccount ID: " << t_account.getID() << endl;
        }
        void printAllAccounts(vector<Account>& t_accounts)
        {
            cout <<"\n All Stored Accounts" << endl;
            for(int i = 1; i < t_accounts.size(); i++)
            {
                this->printName(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                this->printID(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                cout << "\n";
            }
            cout << "\n";
        }
};

class ManageAccounts
{
    private:
        std::vector<Account> m_accounts;
        CheckingAccount* createCheckingAccount(string t_nameOfAccount = "", long int t_balance = 0)
        {
            return new CheckingAccount(t_nameOfAccount, t_balance);
        }
        SavingsAccount* createSavingsAccount(string t_nameOfAccount = "", long int t_balance = 0)
        {
            return new SavingsAccount(t_nameOfAccount, t_balance);
        }
    public:
        ManageAccounts(){}
        ManageAccounts(vector<Account>& t_accounts)
        : m_accounts(t_accounts){}
        void addAccount(string t_nameOfAccount = "", long int t_balance = 0, string t_type = "")
        {
            if(t_type == "Checking")
            {
                m_accounts.push_back(*this->createCheckingAccount(t_nameOfAccount, t_balance));
            }
            else if(t_type == "Savings")
            {
                m_accounts.push_back(*this->createSavingsAccount(t_nameOfAccount, t_balance));
            }
            else
            {
                cout << "Cannot add account, type of account not available..." << endl;
            }
        }
        // Find Account
        Account& findAccount(long int t_ID)
        {
            for(int i = 0; i < m_accounts.size(); i++)
            {
                if(t_ID == m_accounts[i].getID())
                {
                    // return account
                    return m_accounts[i];
                }
            }
            //What to return here? possible end.
            return m_accounts[0];
        }
        vector<Account>& getAccounts()
        {
            return m_accounts;
        }
};

#endif