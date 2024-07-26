/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:02:24 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 03:43:16 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) // Check if the number of arguments is correct
    {
        std::cerr << "Usage: " << argv[0] << " <string to convert>" << std::endl;
        return 1;
    }
	ScalarConvert::convert(argv[1]);
    return 0;
}