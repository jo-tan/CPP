/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:01:30 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:01:33 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void    Contact::setFirstName(std::string str)
{
        this->_firstname = str;
}

void    Contact::setLastName(std::string str)
{
        this->_lastname = str;
}

void    Contact::setPhoneNumber(std::string str)
{
        this->_phonenumber = str;
}

void    Contact::setMemo(std::string str)
{
        this->_memo = str;
}

std::string Contact::getFirstName(void)
{
    return this->_firstname;
}

std::string Contact::getLastName(void)
{
    return this->_lastname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->_phonenumber;
}

std::string Contact::getMemo(void)
{
    return this->_memo;
}
