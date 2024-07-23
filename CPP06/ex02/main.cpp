/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:59 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 14:04:00 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main() {
    Base* ptr = generate();
	Base* ptr2 = generate();

    identify(ptr);
    identify(*ptr);

    identify(ptr2);
	identify(*ptr2);

    delete ptr;
	delete ptr2;
    return 0;
}