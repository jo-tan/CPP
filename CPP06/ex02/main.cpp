/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:59 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 05:38:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    
    std::cout << GREY << "Test Base *generate(void) and identify(Base *p)" << RESET << std::endl;
    Base *ptr = generate();
	Base *ptr2 = generate();
    Base *ptr3 = generate();
    Base *ptr4 = generate();

    identify(ptr);
    identify(*ptr);
    identify(ptr2);
    identify(*ptr2);
    identify(ptr3);
    identify(*ptr3);
    identify(ptr4);
    identify(*ptr4);

    std::cout << GREY << "Test Nullptr" << RESET << std::endl;
    Base *test = NULL;
    identify(test);

    // std::cout << GREY << "Test exception (expecting core dump due to bad_cast is defined in <typeinfo>)" << RESET << std::endl;
    // A a = dynamic_cast<A&>(*ptr);
    // identify(a);

    delete ptr;
	delete ptr2;
    delete ptr3;
    delete ptr4;
    return 0;
}