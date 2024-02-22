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

class Fixed
{
    private:
        int                 _value;
        static const int    _fraction = 8;

    public:
        Fixed();
        Fixed(const Fixed &nbr);
        ~Fixed();
        Fixed & operator = (const Fixed &nbr);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

