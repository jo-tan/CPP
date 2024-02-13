#include "phonebook.hpp"

PhoneBook::PhoneBook() : maxContact(8), newContactIndex(0), numOfContact(0)
{}

PhoneBook::~PhoneBook()
{}

void    PhoneBook::add()
{
    std::string firstname;
    std::string lastname;
    std::string phone;
    std::string memo;

    if (this->numOfContact >= 8)
        std::cout << RED << "WARNING: Adding more than 8 inputs already, the newest will replace the oldest one." << RESET << std::endl;
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
    this->newContactIndex = (this->newContactIndex + 1) % maxContact;
    if (numOfContact < maxContact)
        numOfContact++;
}

std::string PhoneBook::truncateString(const std::string& str, size_t maxLength) const 
{
    if (str.length() > maxLength) 
    {
        return str.substr(0, maxLength - 1) + ".";
    }
    return str;
}

void    PhoneBook::printContact()
{
    std::cout << std::setw(5) << "Index" << "|";
    std::cout << std::setw(10) << "Firstname" << "|";
    std::cout << std::setw(10) << "Lastname" << "|";
    std::cout << std::setw(10) << "Phone" << "|";
    std::cout << std::setw(10) << "Memo" << "|" << std::endl;

    for (int i = 0; i < numOfContact; ++i)
    {
        std::cout << std::setw(5) << i << "|";
        std::cout << std::setw(10) << truncateString(this->array[i].getFirstName(), 10) << "|";
        std::cout << std::setw(10) << truncateString(this->array[i].getLastName(), 10) << "|";
        std::cout << std::setw(10) << truncateString(this->array[i].getPhoneNumber(), 10) << "|";
        std::cout << std::setw(10) << truncateString(this->array[i].getMemo(), 10) << "|" << std::endl;
    }
}

int     PhoneBook::getIndexFromInput(const std::string &input)
{
    if (input.empty())
        return -1;
    for(size_t i = 0; i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
            return -1;
    }
    int index = std::stoi(input);
    if (index < 0 || index > maxContact || index >= numOfContact)
        return -1;
    return index;
}

void    PhoneBook::displayContact(int index)
{
    std::cout << "Firstname : " << this->array[index].getFirstName() << std::endl;
	std::cout << "Lastname : " << this->array[index].getLastName() << std::endl;
	std::cout << "Phone number : " << this->array[index].getPhoneNumber() << std::endl;
	std::cout << "Memo : " << this->array[index].getMemo() << std::endl;
}

void    PhoneBook::search()
{
    std::string userInput;
    int         index;

    if (numOfContact == 0)
    {
        std::cout << "No contact in the book right now..." << std::endl;
        return ;
    }
    printContact();
    std::cout << YELLOW << "Type an index number to obtain full information: " << RESET;
    std::getline(std::cin, userInput);
    index = getIndexFromInput(userInput);
    if (index == -1)
    {
        std::cout << RED << "Invalid input or contact not found!" << RESET << std::endl;
        return;
    }
    displayContact(index);
    std::cout << YELLOW << "Press Enter to comtinur..." << RESET;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

