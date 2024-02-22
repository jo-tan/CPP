/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:04:05 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/22 16:04:32 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed & Fixed::operator = (const Fixed &nbr)
{
    /*std::cout << "Copy assignment operator called" << std::endl;*/
    if (this != &nbr)
        this->_value = nbr.getRawBits();

    return *this;
}

bool Fixed::operator > (const Fixed &nbr) const
{
    if (this->_value > nbr.getRawBits())
        return true;
    return false;
}

bool Fixed::operator < (const Fixed &nbr) const
{
    if (this->_value < nbr.getRawBits())
        return true;
    return false;
}

bool Fixed::operator >= (const Fixed &nbr) const
{
    if (this->_value >= nbr.getRawBits())
        return true;
    return false;
}

bool Fixed::operator <= (const Fixed &nbr) const
{
    if (this->_value <= nbr.getRawBits())
        return true;
    return false;
}

bool Fixed::operator == (const Fixed &nbr) const
{
    if (this->_value == nbr.getRawBits())
        return true;
    return false;
}

bool Fixed::operator != (const Fixed &nbr) const
{
    return !(*this == nbr);
}
Fixed Fixed::operator + (const Fixed &nbr)
{
    Fixed res;

    res._value = this->_value + nbr._value;
    return res;
}

Fixed Fixed::operator - (const Fixed &nbr)
{
    Fixed res;

    res._value = this->_value - nbr._value;
    return res;
}

Fixed Fixed::operator * (const Fixed &nbr)
{
    return Fixed(this->toFloat() * nbr.toFloat());
}

Fixed Fixed::operator / (const Fixed &nbr)
{
    return Fixed(this->toFloat() / nbr.toFloat());
}

// Prefix increment operator (++var)
Fixed Fixed::operator ++ ()
{
    ++_value;
    return *this;
}

// Postfix increment operator (var++)
Fixed Fixed::operator ++ (int)
{
    Fixed old = *this;
    ++_value;
    return old;
}

Fixed Fixed::operator -- ()
{
    --_value;
    return *this;
}

Fixed Fixed::operator -- (int)
{
    Fixed old = *this;
    --_value;
    return old;
}
