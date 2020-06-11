#ifndef ACCOUNTS__HPP_
#define ACCOUNTS__HPP_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

class AccountState
{
    private:
        int m_money;
        std::string m_description;
    public:
        AccountState(int t_money, std::string t_description)
        : m_money(t_money), m_description(t_description)
        {}
        int getMoney()
        {
            return m_money;
        }
        std::string getDescription()
        {
            return m_description;
        }
};

class RecieptHistory
{
    private:
        std::vector<AccountState> m_states;
    public:
        void pushState(AccountState t_state)
        {
            m_states.push_back(t_state);
        }
        void printHistory()
        {
            std::cout << "Transaction Type\tAmount\n" << std::endl;
            for(int i = 0; i < m_states.size(); i++)
            {
                std::cout <<  m_states[i].getDescription() << ":\t\t$" << m_states[i].getMoney() << std::endl;
            }
        }
};

class Account
{
    private:
        int m_money;
        std::string m_description;
        std::string m_nameOfAccount;
    public:
        Account()
        : m_money(0), m_nameOfAccount(""), m_description("")
        {}
        Account(int t_money, std::string t_name, std::string t_description="")
        : m_money(t_money), m_nameOfAccount(t_name), m_description(t_description)
        {}
        int getMoney()
        {
            return m_money;
        }
        void setMoney(int t_money)
        {
            m_money = t_money;
        }
        std::string getDescription()
        {
            return m_description;
        }
        void setDescription(std::string t_description)
        {
            m_description = t_description;
        }
        std::string getNameOfAccount()
        {
            return m_nameOfAccount;
        }
        void setNameOfAccount(std::string t_nameOfAccount)
        {
            m_nameOfAccount = t_nameOfAccount;
        }
        AccountState createAccountState()
        {
            return *new AccountState(m_money,m_description);
        }

};

class Bank
{
    private:
        std::vector<Account> m_listOfAccounts;
        std::vector<RecieptHistory> m_listOfHistory;
        Account* createAccount(std::string t_name)
        {
            return new Account(0, t_name);
        }
        RecieptHistory createHistory()
        {
            return *new RecieptHistory();
        }
    public:
        void pushAccount(std::string t_name)
        {
            m_listOfAccounts.push_back(*createAccount(t_name));
            m_listOfHistory.push_back(createHistory());
        }
        Account getAccount(std::string t_name)
        {
            int i = 0;
            while(i < m_listOfAccounts.size())
            {
                if(m_listOfAccounts[i].getNameOfAccount() == t_name)
                {
                    break;
                }
                i++;
            }
            return m_listOfAccounts[i];
        }
};

#endif