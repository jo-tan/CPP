#include "phonebook.hpp"

void    Book::setFirstName(std::string str)
{
        _firstname = str;
}

void    Book::setLastName(std::string str)
{
        _lasttname = str;
}

void    Book::setPhoneNumber(std::string str)
{
        _phonenumber = str;
}

void    Book::setEmail(std::string str)
{
        _email = str;
}

void    Book::setMemo(std::string str)
{
        _memo = str;
}

std::string Book::getFirstName(void)
{
    return (_firstname);
}

std::string Book::getLastName(void)
{
    return (_lastname);
}

std::string Book::getPhoneNumber(void)
{
    return (_phonenumber);
}

std::string Book::getEmail(void)
{
    return (_email);
}

std::string Book::getMemo(void)
{
    return (_memo);
}