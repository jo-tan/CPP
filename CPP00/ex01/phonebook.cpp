#include "phonebook.hpp"

PhoneBook::PhoneBook():maxContact(8),newContactIndex(0) ,numOfContact(0)
{}

PhoneBook::~PhoneBook()
{}

void    PhoneBook::add()
{
    std::string firstname;
    std::string lastname;
    std::string phone;
    std::string memo;

    if (this->newContactIndex == 8)
        this->newContactIndex = 0;
    std::cout << "First name: ";
    getline(std::cin, firstname);
    std::cout << "Last name: ";
    getline(std::cin, lastname);
    std::cout << "Phone number: ";
    getline(std::cin, phone);
    std::cout << "Memo: ";
    getline(std::cin, memo);
    this->array[this->newContactIndex].setFirstName(firstname);
    this->array[this->newContactIndex].setLastName(lastname);
    this->array[this->newContactIndex].setPhoneNumber(phone);
    this->array[this->newContactIndex].setMemo(memo);
    this->newContactIndex ++;
    if (newContactIndex < 8)
        numOfContact++;
}