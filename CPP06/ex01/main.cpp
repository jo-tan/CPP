/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:03:12 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 02:59:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	std::cout << "Start TEST...\n\n"
	<< BLUE << "1. Assigned a ptr1 to the address of data\n"
	<< "2. Serialize data to a uintptr_t obj, and then deserialize obj to a data pointer"
	<< std::endl;
	Data data = { 'a', 10, 20.0, 30.0f};
	uintptr_t obj = Serializer::serialize(&data);
	Data *ptr1 = &data;
	Data *deserialize = Serializer::deserialize(obj);
	
	std::cout << "Now, here we are checing if the deserialized ptr points to the same address as ptr1" << RESET << std::endl;
	if (ptr1 == deserialize) {
		std::cout << GREEN << "Two pointers are identical." << RESET << std::endl;
	} else {
		std::cout << RED << "Two pointers are NOT identical." << RESET << std::endl;
	}

	std::cout << BLUE << "\nCreate a new data called data2 and assign a ptr2 to the address of this data struct\n"
	<< "Checking that ptr and ptr2 are different with each other" << RESET << std::endl;
	Data data2 = { 'b', 30, 20.0, 10.0f};
	Data *ptr2 = &data2;
	if (ptr1 == ptr2) {
		std::cout << GREEN << "Two pointers are identical." << RESET << std::endl;
	} else {
		std::cout << RED << "Two pointers are NOT identical." << RESET << std::endl;
	}
	
	std::cout << BLUE << "\nAlso checking that ptr2 and deserialize ptr are different with each other" << RESET << std::endl;
	if (ptr2 == deserialize) {
		std::cout << GREEN << "Two pointers are identical." << RESET << std::endl;
	} else {
		std::cout << RED << "Two pointers are NOT identical." << RESET << std::endl;
	}
	
	std::cout << BLUE << "\nAssign the deserialize ptr to the address of data2\n"
	<< "Checking that deserialized ptr and ptr2 are SAME with each other" << RESET << std::endl;
	uintptr_t obj2 = Serializer::serialize(&data2);
	deserialize = Serializer::deserialize(obj2);
	if (ptr2 == deserialize) {
		std::cout << GREEN << "Two pointers are identical." << RESET << std::endl;
	} else {
		std::cout << RED << "Two pointers are NOT identical." << RESET << std::endl;
	}

	std::cout << BLUE << "\nNow the deserialize ptr should be different with ptr1" << RESET << std::endl;	
	if (ptr1 == deserialize) {
		std::cout << GREEN << "Two pointers are identical." << RESET << std::endl;
	} else {
		std::cout << RED << "Two pointers are NOT identical." << RESET << std::endl;
	}
	std::cout << "\nEND OF TEST\n" << std::endl;
}