/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:49 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 05:21:35 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;241m"


class Base{
    public:
        virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);

void identify(Base *p);

void identify(Base &p);

#endif