/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:10:06 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:10:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You have to create a program which outputs the value of a certain amount of bitcoin
on a certain date.
This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates
to evaluate.
Your program must respect these rules:
• The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.

You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.*/

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

typedef std::string string;

class BitcoinExchange
{
private:
    std::map<std::string, std::string>    _data;

    std::string  previousDate(const std::string& date);
    std::string  nextDate(const std::string& date);
    std::string  trim(const std::string& str);

    void    validateNumber(const std::string &str);
    bool    fileExists(const std::string &filename);
    bool    fileIsEmpty(const std::string &filename);
    bool    validDate(const std::string &date);
    bool    isLeapYear(int year);
    bool    ft_all_of(const std::string &str, int (*isDigit)(int));

    int     ft_stoi(const std::string &str);
    double  ft_stod(const std::string &str);
    std::string  ft_to_string(int value);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void parse(const std::string &filename);
};
