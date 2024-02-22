/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:42:12 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/22 18:22:15 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()  : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = nbr;
}

Fixed::Fixed(const int iNbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = (iNbr << Fixed::_fraction);
}

Fixed::Fixed(const float fPt)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(fPt * (1 << Fixed::_fraction));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &nbr)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &nbr)
        this->_value = nbr.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << Fixed::_fraction));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fraction);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &f)
{
	output << f.toFloat();
	return (output);
}