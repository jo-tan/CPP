/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:49:42 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 08:51:38 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void printElement(T const &element) {
    std::cout << element << std::endl;
}

template <typename T, typename F>
void iter(T* array, size_t size, F function) {
    for (size_t i = 0; i < size; ++i) {
        function(array[i]);
    }
}
#endif
