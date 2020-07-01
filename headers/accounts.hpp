#ifndef ACCOUNTS__HPP_
#define ACCOUNTS__HPP_

#include <iostream>
// #include <iomanip>
#include <stdlib.h>
#include <vector>
#include "contacts.hpp"

using namespace std;

class I_Account
{
    public:
        virtual long int& getBalance() = 0;
        virtual void setBalance(long int t_newBalance) = 0;
        virtual string& getName() = 0;
        virtual long int getID() = 0;
        virtual string getType() = 0;
        virtual ContactInfo* getContacts() = 0;
};

class Account : public I_Account
{
    protected:
        long int m_balance;
        string m_nameOfAccount;
        long int m_ID = rand() % 9999999 + 1;
        string m_type;
        ContactInfo contact;
    public:
        long int& getBalance() final
        {
            return m_balance;
        }
        void setBalance(long int t_newBalance) final
        {
            m_balance = t_newBalance;
        }
        string& getName() final
        {
            return m_nameOfAccount;
        }
        long int getID() final
        {
            return m_ID;
        }
        string getType() final
        {
            return m_type;
        }
        ContactInfo* getContacts() final
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