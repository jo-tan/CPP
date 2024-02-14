#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

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
        std::string     _firstname;
        std::string     _lastname;
        std::string     _phonenumber;
        std::string     _memo;
};

#endif