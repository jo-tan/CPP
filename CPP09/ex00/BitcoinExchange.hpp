/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:10:06 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/10 11:18:44 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

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

    void parse(const char *filename);
};
