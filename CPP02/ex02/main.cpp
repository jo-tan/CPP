/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 08:39:55 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 08:40:30 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	std::cout << "===Standard tests from subject===" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl << std::endl;
	std::cout << "===other random tests===" << std::endl;
	int   i;
	Fixed c;
	Fixed d;
	i = 5;
	std::cout << "i = 5: " << i << std::endl;
	c = ++i;
	std::cout << "c = ++i: " << c << "  i: " << i << std::endl;
	d = i++;
	std::cout << "d = i++: " << d << "  i: " << i << std::endl;
	c = --i;
	std::cout << "c = --i: " << c << "  i: " << i << std::endl;
	d = i--;
	std::cout << "d = i--: " << d << "  i: " << i << std::endl << std::endl;
	a = i;
	std::cout << "i: " << i << std::endl;
	std::cout << "a = i: " << a << std::endl;
	std::cout << "a > c: " << ((a > c)?"True":"False") << std::endl;
	std::cout << "a > d: " << ((a > d)?"True":"False") << std::endl;
	std::cout << "c == d: " << ((c == d)?"True":"False") << std::endl;
	std::cout << "c != d: " << ((c != d)?"True":"False") << std::endl;
	std::cout << "--a as Fixed object: " << --a << std::endl;
	std::cout << "a-- as Fixed object: " << a-- << std::endl << std::endl;
	a = 42.6f;
	c = 3.1f;
	std::cout << "value a: " << a << " value c: " << c << std::endl;
	std::cout << "a + c: " << (a + c) << std::endl;
	std::cout << "a - c: " << (a - c) << std::endl;
	std::cout << "a * c: " << (a * c) << std::endl;
	std::cout << "a / c: " << (a / c) << std::endl;
	return 0;
}
