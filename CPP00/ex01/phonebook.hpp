#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

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
};

#endif