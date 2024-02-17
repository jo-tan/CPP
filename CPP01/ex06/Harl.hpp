#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

enum    Level {DEBUG, INFO, WARNING, ERROR, INVALID};

class   Harl
{
    public:
        Harl();
        ~Harl();
        void	complain(std::string level);

    private:
        void	debug(void);
	    void	info(void);
	    void	warning(void);
	    void	error(void);
        void    invalid(void);
        void    call(std::string input, std::string level, void (Harl::*func)(void));
        Level   getLevel(std::string const &level);
};

#endif