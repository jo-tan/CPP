/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:40 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 14:03:41 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

Base* generate(void)
{
    srand(time(0));
    switch (rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return NULL;// To silence compiler warning
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    identify(&p);
}