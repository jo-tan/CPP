/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:31:39 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:31:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void    Harl::call(std::string input, std::string level, void (Harl::*func)(void))
{
    if (level == "INVALID")
    {
        (this->* func)();
        return ;
    }
    input == level ? (this->* func)() : void();
}

void    Harl::complain(std::string level)
{
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") 
    {
            call(level, "INVALID", &Harl::invalid);
            return ;
    }
    call(level, "DEBUG", &Harl::debug);
	call(level, "INFO", &Harl::info);
	call(level, "WARNING", &Harl::warning);
	call(level, "ERROR", &Harl::error);
}

void	Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::invalid(void)
{
    std::cout << "Invalid complain" << std::endl;
}
