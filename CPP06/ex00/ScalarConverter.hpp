/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:02:03 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/24 19:55:12 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Write a class ScalarConverter that will contain only one static methods "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar types :
• char
• int
• float
• double
As this class doesn’t need to store anything at all, this class must not be instanciable by
users.
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.

Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.

Write a program to test that your class works as expected.
You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

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
		static bool validateInput(std::string const &literal);
		static int getPrecision(std::string const &literal);
		
		static void printChar(double d);
		static void printInt(double d);
		static void printFloat(double d, std::string const &literal);
		static void printDouble(double d, std::string const &literal);
		
		// static void printDoubleOverflow();
		// static void printIntOverflow();
		// static void printCharOverflow();
		// static void printFloatOverflow();
		
		static bool floatOverflow(double d);
		static bool checkQuotePair(std::string const &literal);
		static bool atLeastOneNum(std::string const &literal);
	
	public:
		ScalarConvert();
		static void convert(std::string const &input);

		class NonDisplayableException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class ImpossibleException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};


#endif