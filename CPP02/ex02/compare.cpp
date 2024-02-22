/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:03:26 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/22 16:03:28 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed const &Fixed::min(Fixed &n1, Fixed &n2)
{
    if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const &Fixed::min(Fixed const &n1, Fixed const &n2)
{
    if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const &Fixed::max(Fixed &n1, Fixed &n2)
{
    if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const &Fixed::max(Fixed const &n1, Fixed const &n2)
{
    if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}
