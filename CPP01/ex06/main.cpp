/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:33:08 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:33:10 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl    harl;

    std::cout << RED << "Test error cases:" << RESET << std::endl;
    harl.complain("");
    harl.complain("hi");
    std::cout << std::endl;
    std::cout << GREEN << "Test normal cases: DEBUG < INFO < WARNING < ERROR" << RESET << std::endl;
    std::cout << YELLOW << "Test info: should show INFO, WARNING, ERROR" << RESET << std::endl;
    harl.complain("INFO");
    std::cout << std::endl << std::endl;
    std::cout << YELLOW << "Test debug: should show DEBUG, INFO, WARNING, ERROR" << RESET << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl << std::endl;
    std::cout << YELLOW << "Test warning: should show WARNING, ERROR" << RESET << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl << std::endl;
    std::cout << YELLOW << "Test error: should show only ERROR" << RESET << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    return 0;
}
