#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();
    
        void    setFirstName(std::string str);
        void    setLastName(std::string str);
        void    setPhoneNumber(std::string str);
        void    setMemo(std::string str);

        std::string     getFirstName(void);
        std::string     getLastName(void);
        std::string     getPhoneNumber(void);
        std::string     getMemo(void);
    private:
        std::string     firstname;
        std::string     lastname;
        std::string     phonenumber;
        std::string     memo;
};

#endif