/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:10:44 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:10:46 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Usage: ./BitcoinExchange <data_file>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;

	exchange.parse(av[1]);

	return (0);
}
