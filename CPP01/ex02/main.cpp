/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:35:41 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:35:43 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable: ";
	std::cout << &str << std::endl;
	std::cout << "The memory address held by stringPTR     : ";
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF     : ";
	std::cout << &stringREF << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "The value of the string variable : ";
	std::cout << str << std::endl;
	std::cout << "The value pointed to by stringPTR: ";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: ";
	std::cout << stringREF << std::endl << std::endl;

	return 0;
}
