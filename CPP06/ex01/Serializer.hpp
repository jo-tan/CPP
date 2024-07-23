/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:02:55 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 14:02:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Implement a class Serializer, who will not be initializable by the user by any way,
with the following static methods:
uintptr_t serialize(Data* ptr);
It takes a pointer and converts it to the unsigned integer type uintptr_t.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a pointer to Data.
Write a program to test that your class works as expected.
You must create a non-empty (it means it has data members) Data structure.
Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
Do not forget to turn in the files of your Data structure.

#include <stdint.h>

class Data
{
	public:
		int a;
		float b;
		char c;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

		static  uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};