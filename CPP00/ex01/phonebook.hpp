#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class Book
{
    public:
        void    setFirstName(std::string str);
        void    setLastName(std::string str);
        void    setPhoneNumber(std::string str);
        void    setEmail(std::string str);
        void    setMemo(std::string str);

        std::string     getFirstName(void);
        std::string     getLastName(void);
        std::string     getPhoneNumber(void);
        std::string     getEmail(void);
        std::string     getMemo(void);
    private:
        std::string     _firstname;
        std::string     _lastname;
        std::string     _phonenumber;
        std::string     _email;
        std::string     _memo;
}

#endif