/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:02:03 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 04:41:44 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "cmath"
#include <limits>
#include <sstream>
#include <iomanip>
#include <cerrno>
#include <stdio.h>

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConvert {

	private:
		ScalarConvert();
		ScalarConvert(std::string str);
		~ScalarConvert();
		ScalarConvert(ScalarConvert const &other);
		static void handleInfPseudoLiteral(std::string const &literal);
		static void handleNanPseudoLiteral(std::string const &literal);
		static void handleNumericLiteral(std::string const &literal);
		static void handleFloatLiteral(std::string const &literal);
		static void handleDoubleLiteral(std::string const &literal);
		static void handleCharLiteral(std::string const &literal);
		static void handleIntLiteral(std::string const &literal);
		static int countDecimalPlaces(const std::string &s);
		static bool validateNumericInput(std::string const &literal);
		static int getPrecision(std::string const &literal);
		
		static void printChar(double d);
		static void printInt(double d);
		static void printFloat(double d, std::string const &literal);
		static void printDouble(double d, std::string const &literal);
		
		static bool isCharLiteral(std::string const &literal);
		static bool checkQuotePair(std::string const &literal);
		static bool atLeastOneNum(std::string const &literal);
	
	public:
		static void convert(std::string const &input);
};


#endif