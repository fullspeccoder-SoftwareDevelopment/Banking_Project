#ifndef CONTACTS__HPP_
#define CONTACTS__HPP_

#include <iostream>

using namespace std;

class ContactInfo
{
    private:
        // phone number, contact address, emergency contact, work number
        string m_phoneNumber;
        string m_workNumber;
        string m_house;
        string m_city;
        string m_state;
        string m_zipCode;
    public:
        ContactInfo()
        {}
        string getItem(int t_choice)
        {
            switch(t_choice)
            {
                case 1:
                    return m_phoneNumber;
                case 2:
                    return m_workNumber;
                case 3:
                    return m_house;
                case 4:
                    return m_city;
                case 5:
                    return m_state;
                case 6:
                    return m_zipCode;
                default:
                    return "Could Not Get Info";
            }
        }
        void setItem(string t_item, int t_choice)
        {
            switch(t_choice)
            {
                case 1:
                    m_phoneNumber = t_item;
                    break;
                case 2:
                    m_workNumber = t_item;
                    break;
                case 3:
                    m_house = t_item;
                    break;
                case 4:
                    m_city = t_item;
                    break;
                case 5:
                    m_state = t_item;
                    break;
                case 6:
                    m_zipCode = t_item;
            }
        }
};

#endif