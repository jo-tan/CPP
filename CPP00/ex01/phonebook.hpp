#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib> // for atoi
#include <string>
#include "contact.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

        void    add(void);
        void    search();
    private:
        const int   maxContact;
        int         newContactIndex;
        int         numOfContact;
        Contact     array[8];

        std::string truncateString(const std::string& str, size_t maxLength) const;
        void        printContact();
        void        displayContact(int index);
        int         getIndexFromInput(const std::string &input);
};

#endif