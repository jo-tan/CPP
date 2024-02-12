#include "contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void    Contact::setFirstName(std::string str)
{
        this->firstname = str;
}

void    Contact::setLastName(std::string str)
{
        this->lastname = str;
}

void    Contact::setPhoneNumber(std::string str)
{
        this->phonenumber = str;
}

void    Contact::setMemo(std::string str)
{
        this->memo = str;
}

std::string Contact::getFirstName(void)
{
    return this->firstname;
}

std::string Contact::getLastName(void)
{
    return this->lastname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->phonenumber;
}

std::string Contact::getMemo(void)
{
    return this->memo;
}