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
        long int& getBalance()
        {
            return m_balance;
        }
        string& getName()
        {
            return m_nameOfAccount;
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
            cout << "\n\t\t\t" << t_account.getName() << "'s Account\n" << endl;
            cout << "\t\t\t\t\tAccount Balance: " << t_account.getBalance() << "\n" << endl;
        }
        void printName(Account& t_account)
        {
            cout << "\nName Of Account: " << t_account.getName() << endl;
        }
        void printBalance(Account& t_account)
        {
            cout << "\nBalance: " << t_account.getBalance() << endl;
        }
        void printAllAccounts(vector<Account>& t_accounts)
        {
            cout <<"\n All Stored Accounts" << endl;
            for(int i = 0; i < t_accounts.size(); i++)
            {
                this->printName(t_accounts[i]);
                cout << "\n";
            }
            cout << "\n";
        }
};

class StoreAccounts
{
    private:
        std::vector<Account> m_accounts;
        PrintAccounts m_printer;
        CheckingAccount* createCheckingAccount(string t_nameOfAccount = "", long int t_balance = 0)
        {
            return new CheckingAccount(t_nameOfAccount, t_balance);
        }
        SavingsAccount* createSavingsAccount(string t_nameOfAccount = "", long int t_balance = 0)
        {
            return new SavingsAccount(t_nameOfAccount, t_balance);
        }
    public:
        StoreAccounts(){}
        StoreAccounts(vector<Account>& t_accounts)
        : m_accounts(t_accounts){}
        void addAccount(string t_nameOfAccount = "", long int t_balance = 0, string t_type = "")
        {
            if(t_type == "Checking")
            {
                m_accounts.push_back(*this->createCheckingAccount(t_nameOfAccount, t_balance));
            }
            else
            {
                m_accounts.push_back(*this->createSavingsAccount(t_nameOfAccount, t_balance));
            }
            
        }
        vector<Account>& getAccounts()
        {
            return m_accounts;
        }
        PrintAccounts getPrinter()
        {
            return m_printer;
        }
};

#endif