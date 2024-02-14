/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:01:56 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:01:58 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
    PhoneBook   PhoneBook;
    std::string input;
    std::string add = "ADD";
    std::string search = "SEARCH";
    std::string exit = "EXIT";

    system("clear");
    std::cout << MAGENTA << "Hello! You are in your crappy phonebook now. =^. .^=" << RESET << std::endl;
    while (42)
    {
        std::cout << YELLOW << "Please input the command ADD, SEARCH or EXIT : " << RESET;
		getline(std::cin, input);
		if (input == add)
			PhoneBook.add();
		else if (input == search)
			PhoneBook.search();
		else if (input == exit)
		{
			std::cout << MAGENTA << "Goodbye and see you next time! =^. .^=ฅ" << RESET << std::endl;
			break;
		}
        else
            std::cout << RED << "Invalid command... /ᐠ - ˕ -マ" << RESET << std::endl;
	}
    return 0;
}
