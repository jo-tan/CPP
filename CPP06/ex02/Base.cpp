/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:40 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 05:32:47 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base *generate()
{
    switch (rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p)) std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "Type C" << std::endl;
    else std::cout << "ERROR: NULL pointer or unknown type" << std::endl;
}

void identify(Base &p)
{
    try{
        identify(&p);
    } catch (const std::exception &e) {
        std::cout << "Dynamic_cast failed: " << e.what() << std::endl;
    }
}