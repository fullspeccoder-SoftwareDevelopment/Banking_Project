#ifndef ACCOUNTS__HPP_
#define ACCOUNTS__HPP_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "contacts.hpp"

using namespace std;

class Account
{
    protected:
        long int m_balance;
        string m_nameOfAccount;
        long int m_ID = rand() % 9999999 + 1;
        string m_type;
        ContactInfo contact;
    public:
        long int& getBalance()
        {
            return m_balance;
        }
        void setBalance(long int t_newBalance)
        {
            m_balance = t_newBalance;
        }
        string& getName()
        {
            return m_nameOfAccount;
        }
        long int getID()
        {
            return m_ID;
        }
        string getType()
        {
            return m_type;
        }
        ContactInfo* getContacts()
        {
            return &contact;
        }
};

class CheckingAccount : public Account
{
    public:
        CheckingAccount(string t_name, long int t_amount=0)
        {
            m_type = "Checking";
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class SavingsAccount : public Account
{
    public:
        SavingsAccount(string t_name, long int t_amount=0)
        {
            m_type = "Savings";
            m_nameOfAccount = t_name;
            m_balance = t_amount;
        }
};

class PrintAccounts
{
    private:
        void printName(Account& t_account)
        {
            cout << "\nName Of Account: \n\t" << t_account.getName() << endl;
        }
        void printBalance(Account& t_account)
        {
            cout << "\nBalance: \n\t" << t_account.getBalance() << endl;
        }
        void printID(Account& t_account)
        {
            cout << "\nAccount ID: \n\t" << t_account.getID() << endl;
        }
        void printPhoneNumber(Account& t_account)
        {
            cout << "\nPhone Number: \n\t";
            cout <<  t_account.getContacts()->getItem(1) << endl;
        }
        void printWorkNumber(Account& t_account)
        {
            cout << "\nWork Number: \n\t";
            cout << t_account.getContacts()->getItem(2) << endl;
        }
        void printContactInfo(Account& t_account)
        {
            cout << "\nContact Information: " << endl;
            for(int i = 3; i < 7; i++)
            {
                cout << "\t" << t_account.getContacts()->getItem(i) << endl;
            }
        }
    public:
        void printAccountInfo(Account& t_account)
        {
            this->printName(t_account);
            this->printBalance(t_account);
            this->printID(t_account);
            this->printPhoneNumber(t_account);
            this->printWorkNumber(t_account);
            this->printContactInfo(t_account);
        }
        void printAllAccounts(vector<Account>& t_accounts)
        {
            cout <<"\n\tAll Stored Accounts" << endl;
            for(int i = 0; i < t_accounts.size(); i++)
            {
                if(t_accounts[i].getType() == "Checking" || t_accounts[i].getType() == "Savings")
                {
                this->printName(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                this->printID(t_accounts[i]);
                // FOR TESTING PURPOSES ONLY
                cout << "\n";
                }
            }
        }
};

class ManageAccounts
{
    private:
        std::vector<Account> m_accounts;
        int m_index = 0;
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
            if(t_type == "Checking" || t_type == "checking")
            {
                m_accounts.push_back(*this->createCheckingAccount(t_nameOfAccount, t_balance));
            }
            else if(t_type == "Savings" || t_type == "savings")
            {
                m_accounts.push_back(*this->createSavingsAccount(t_nameOfAccount, t_balance));
            }
            else
            {
                cout << "Cannot add account, type of account not available..." << endl;
            }
            m_index = m_accounts.size() - 1;
        }
        // Find Account
        Account& findAccount(long int t_ID)
        {
            for(int i = 0; i < m_accounts.size() - 1; i++)
            {
                if(t_ID == m_accounts[i].getID())
                {
                    // return account
                    m_index = i;
                    return m_accounts[i];
                }
            }
            //What to return here? possible end.
            return m_accounts[0];
        }
        void deleteAccount()
        {
            Account* emptyAccount = new Account();
            m_accounts[m_index] = *emptyAccount;
            cout << m_index;
        }
        vector<Account>& getAccounts()
        {
            return m_accounts;
        }
};

#endif