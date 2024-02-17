/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:32:39 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:13:31 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void    Harl::call(std::string /*input*/, std::string level, void (Harl::*func)(void))
{
    if (level == "INVALID")
    {
        (this->* func)();
        return ;
    }
    (this->* func)();
}

Level   Harl::getLevel(std::string const &level)
{
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return INVALID;
}

void    Harl::complain(std::string level)
{
    Level   Loglevel = getLevel(level);
    switch(Loglevel)
    {
        case DEBUG:
            call(level, "DEBUG", &Harl::debug);
        case INFO:
	        call(level, "INFO", &Harl::info);
        case WARNING:
	        call(level, "WARNING", &Harl::warning);
        case ERROR:
        {
	        call(level, "ERROR", &Harl::error);
            break;
        }
        default:
        {
            call(level, "INVALID", &Harl::invalid);
            break;
        }
    }
}

void	Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}
void	Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void	Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void	Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::invalid(void)
{
    std::cout << "Invalid complain" << std::endl << std::endl;
}
