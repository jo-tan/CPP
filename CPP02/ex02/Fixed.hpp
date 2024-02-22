/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:40:46 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:41:48 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _value;
        static const int    _fraction = 8;

    public:
        Fixed();
        Fixed(const Fixed &nbr);
        Fixed(const int iNbr);
        Fixed(const float fPt);
        ~Fixed();
        Fixed & operator = (const Fixed &nbr);
        bool operator > (const Fixed &nbr) const;
        bool operator < (const Fixed &nbr) const;
        bool operator >= (const Fixed &nbr) const;
        bool operator <= (const Fixed &nbr) const;
        bool operator == (const Fixed &nbr) const;
        bool operator != (const Fixed &nbr) const;
        Fixed operator + (const Fixed &nbr);
        Fixed operator - (const Fixed &nbr);
        Fixed operator * (const Fixed &nbr);
        Fixed operator / (const Fixed &nbr);
        Fixed operator ++ ();
        Fixed operator ++ (int);
        Fixed operator -- ();
        Fixed operator -- (int);

        static Fixed const &min(Fixed &n1, Fixed &n2);
        static Fixed const &min(Fixed const &n1, Fixed const &n2);
        static Fixed const &max(Fixed &n1, Fixed &n2);
        static Fixed const &max(Fixed const &n1, Fixed const &n2);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);
