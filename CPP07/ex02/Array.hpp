/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:50:05 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 08:51:58 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;


	public:
		Array();
		Array(unsigned int n);
    Array(const Array &other);
    ~Array(); 

    Array &operator=(const Array &other);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    size_t size() const;
};

#include "Array.tpp"

#endif
