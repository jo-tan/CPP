#include "phonebook.hpp"

PhoneBook::PhoneBook() : _maxContact(8), _newContactIndex(0), _numOfContact(0)
{}

PhoneBook::~PhoneBook()
{}

void    PhoneBook::add()
{
    std::string firstname;
    std::string lastname;
    std::string phone;
    std::string memo;

    if (this->_numOfContact >= 8)
        std::cout << RED << "WARNING: Adding more than 8 inputs already, the newest will replace the oldest one." << RESET << std::endl;
    std::cout << "First name: ";
    getline(std::cin, firstname);
    std::cout << "Last name: ";
    getline(std::cin, lastname);
    std::cout << "Phone number: ";
    getline(std::cin, phone);
    std::cout << "Memo: ";
    getline(std::cin, memo);
    this->_array[this->_newContactIndex].setFirstName(firstname);
    this->_array[this->_newContactIndex].setLastName(lastname);
    this->_array[this->_newContactIndex].setPhoneNumber(phone);
    this->_array[this->_newContactIndex].setMemo(memo);
    this->_newContactIndex = (this->_newContactIndex + 1) % _maxContact;
    if (_numOfContact < _maxContact)
        _numOfContact++;
}

std::string PhoneBook::_truncateString(const std::string& str, size_t maxLength) const 
{
    if (str.length() > maxLength) 
    {
        return str.substr(0, maxLength - 1) + ".";
    }
    return str;
}

void    PhoneBook::_printContact()
{
    std::cout << std::setw(5) << "Index" << "|";
    std::cout << std::setw(10) << "Firstname" << "|";
    std::cout << std::setw(10) << "Lastname" << "|";
    std::cout << std::setw(10) << "Phone" << "|";
    std::cout << std::setw(10) << "Memo" << "|" << std::endl;

    for (int i = 0; i < _numOfContact; ++i)
    {
        std::cout << std::setw(5) << i << "|";
        std::cout << std::setw(10) << _truncateString(this->_array[i].getFirstName(), 10) << "|";
        std::cout << std::setw(10) << _truncateString(this->_array[i].getLastName(), 10) << "|";
        std::cout << std::setw(10) << _truncateString(this->_array[i].getPhoneNumber(), 10) << "|";
        std::cout << std::setw(10) << _truncateString(this->_array[i].getMemo(), 10) << "|" << std::endl;
    }
}

int     PhoneBook::_getIndexFromInput(const std::string &input)
{
    if (input.empty())
        return -1;
    for(size_t i = 0; i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
            return -1;
    }
    int index = std::stoi(input);
    if (index < 0 || index > _maxContact || index >= _numOfContact)
        return -1;
    return index;
}

void    PhoneBook::_displayContact(int index)
{
    std::cout << "Firstname : " << this->_array[index].getFirstName() << std::endl;
	std::cout << "Lastname : " << this->_array[index].getLastName() << std::endl;
	std::cout << "Phone number : " << this->_array[index].getPhoneNumber() << std::endl;
	std::cout << "Memo : " << this->_array[index].getMemo() << std::endl;
}

void    PhoneBook::search()
{
    std::string userInput;
    int         index;

    if (_numOfContact == 0)
    {
        std::cout << "No contact in the book right now..." << std::endl;
        return ;
    }
    _printContact();
    std::cout << YELLOW << "Type an index number to obtain full information: " << RESET;
    std::getline(std::cin, userInput);
    index = _getIndexFromInput(userInput);
    if (index == -1)
    {
        std::cout << RED << "Invalid input or contact not found!" << RESET << std::endl;
        return;
    }
    _displayContact(index);
    std::cout << YELLOW << "Press Enter to comtinur..." << RESET;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

