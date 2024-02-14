/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:02:27 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:15:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <limits>
#include "contact.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

        void    add(void);
        void    search();
    private:
        const int   _maxContact;
        int         _newContactIndex;
        int         _numOfContact;
        Contact     _array[8];

        std::string _truncateString(const std::string& str, size_t maxLength) const;
        void        _printContact();
        void        _displayContact(int index);
        int         _getIndexFromInput(const std::string &input);
};

#endif
