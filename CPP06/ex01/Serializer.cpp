/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:02 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 14:03:04 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	std::cout << "Serializer::Serializer()" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer::~Serializer()" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer::Serializer(const Serializer& other)" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer& Serializer::operator=(const Serializer& other)" << std::endl;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}