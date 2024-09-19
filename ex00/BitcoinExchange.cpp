/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:10:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/19 12:35:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class InputError : public std::invalid_argument {
public:
    InputError(const std::string& msg) : std::invalid_argument(msg) {}
};

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;

    std::getline(file, line); // skip first line
    while (std::getline(file, line))
    {
        size_t delim = line.find(',');

        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1, line.length()));

        _data[date] = value;
    }

    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

std::string BitcoinExchange::previousDate(const std::string& date) {
    int year = ft_stoi(date.substr(0, 4));
    int month = ft_stoi(date.substr(5, 2));
    int day = ft_stoi(date.substr(8, 2));

    // Days in each month (for non-leap years)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29; // February has 29 days in a leap year
    }

    // Decrement the day
    day--;

    // Check if day is 0 (previous month)
    if (day == 0) {
        month--;

        // Check if month is 0 (December)
        if (month == 0) {
            month = 12;
            year--;
        }

        day = daysInMonth[month];
    }

    // Format the previous date
    std::string newYear = ft_to_string(year);
    std::string newMonth = (month < 10) ? "0" + ft_to_string(month) : ft_to_string(month);
    std::string newDay = (day < 10) ? "0" + ft_to_string(day) : ft_to_string(day);

    return newYear + "-" + newMonth + "-" + newDay;
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


void BitcoinExchange::validateNumber(const std::string &str) {
    double value;

    try {
        // If there's more than one decimal point, throw an error
        size_t decimalPoint = str.find('.');
        if (decimalPoint != std::string::npos) {
            if (str.find('.', decimalPoint + 1) != std::string::npos)
                throw InputError("too many decimal points" + str);
        }

        // If there's a + or - sign check the next characters
        bool hasSign = str[0] == '+' || str[0] == '-';
        for (size_t i = hasSign ? 1 : 0; i < str.length(); i++) {
            if (::isdigit(str[i]) || str[i] == '.')
                continue;
            throw InputError("not a number => " + str);
        }

        value = ft_stod(str);

    } catch (std::exception &e) {
        std::cout << "ECEPTION CATCH" << std::endl;
        throw InputError("not a number => " + str);
    }

    if (value < 0)
        throw InputError("negative number => " + str);

    if (value > 1000.0)
        throw InputError("number too large => " + str);
}


bool BitcoinExchange::ft_all_of(const std::string& str, int (*isDigit)(int)) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isDigit(str[i]))
            return false;
    }

    return true;
}

bool BitcoinExchange::validDate(const std::string &date) {
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);


    if ((!ft_all_of(year, &::isdigit)) ||
        (!ft_all_of(month, &::isdigit)) ||
        (!ft_all_of(day, &::isdigit)))
        return false;

    int yearInt, monthInt, dayInt;

    std::stringstream ssYear(year);
    std::stringstream ssMonth(month);
    std::stringstream ssDay(day);

    ssYear >> yearInt;
    ssMonth >> monthInt;
    ssDay >> dayInt;

    if ((yearInt < 2009 || yearInt > 2022) ||
        (monthInt < 1 || monthInt > 12) ||
        (dayInt < 1 || dayInt > 31))
        return false;

    // Check for specific months with 30 days
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;

    
    // Check for February
    if (monthInt == 2) {
        // Check for leap year
        bool isLeap = isLeapYear(yearInt);
        if (dayInt > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

std::string BitcoinExchange::nextDate(const std::string& date) {
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int yearInt = ft_stoi(year);
    int monthInt = ft_stoi(month);
    int dayInt = ft_stoi(day);

    // Days in each month (for non-leap years)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(yearInt)) {
        daysInMonth[2] = 29; // February has 29 days in a leap year
    }

    // Increment the day
    dayInt++;

    // Check if day exceeds the maximum for the current month
    if (dayInt > daysInMonth[monthInt]) {
        dayInt = 1;
        monthInt++;

        // Check if month exceeds 12 (December)
        if (monthInt > 12) {
            monthInt = 1;
            yearInt++;
        }
    }

    // Format the next date
    std::string nextYear = ft_to_string(yearInt);
    std::string nextMonth = (monthInt < 10) ? "0" + ft_to_string(monthInt) : ft_to_string(monthInt);
    std::string nextDay = (dayInt < 10) ? "0" + ft_to_string(dayInt) : ft_to_string(dayInt);

    return nextYear + "-" + nextMonth + "-" + nextDay;
}

int BitcoinExchange::ft_stoi(const std::string &str) {
    std::stringstream ss(str);
    int value;

    ss >> value;

    return value;
}

double BitcoinExchange::ft_stod(const std::string &str) {
    std::stringstream ss(str);
    double value;

    ss >> value;

    return value;
}

std::string BitcoinExchange::ft_to_string(int value) {
    std::stringstream ss;

    ss << value;

    return ss.str();
}


void BitcoinExchange::parse(const char *filename) {
    std::ifstream   file(filename);
    std::string          line;

    if (!file.is_open()) {
        throw InputError("Error: file does not exist");
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        throw InputError("Error: file is empty");
    }

    std::getline(file, line); // skip first line

    if (line != "date | value") {
        throw InputError("Error: invalid file format: first line should be \"date | value\"");
    }

    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        if (delim == std::string::npos)
        {
            std::cout << "\033[1;31mError\033[0m: bad input => " << line << "\033[0m" << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1));

        try {
            if (!validDate(date))
                throw InputError("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));

            if(value.empty())
                throw InputError("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));

            validateNumber(value);

            std::map<std::string, std::string>::iterator it;
            std::string prevDate = date;
            it = _data.find(date);

            while (it == _data.end()) {
                const std::string& currentDate = prevDate;
                prevDate = previousDate(currentDate);
                it = _data.find(prevDate);
            }

            std::cout << date << " => " << value  << " = "
                << ft_stod(it->second) * ft_stod(value) << std::endl;

        } catch (std::exception &e) {
            std::cout << "\033[1;31mError\033[0m: " << e.what() << std::endl;
        }

    }

    file.close();
}