/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:10:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/10 11:18:56 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, const char **av)
{

	if (ac != 2) {
		std::cerr << "Usage: ./BitcoinExchange <data_file>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange exchange;
		exchange.parse(av[1]);
	} catch (const std::exception &e) {
    	std::cout << "Exception caught: " << e.what() << std::endl;
  	}
	return (0);
}
