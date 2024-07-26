/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 08:49:52 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 08:49:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    std::cout << "\033[34mTest Int Array\033[0m" << std::endl;
    int IntArray[] = {1, 2, 3, 4, 5};
    iter(IntArray, 5, printElement<int>);

    std::cout << "\033[34mTest Char Array\033[0m" << std::endl;
    char charArray[] = {'a', 'b', 'c'};
    iter(charArray, 3, printElement<char>);

    std::cout << "\033[34mTest String Array\033[0m" << std::endl;
    std::string StrArray[] = {"Hello", "Good day!"};
    iter(StrArray, 2, printElement<std::string>);


    return 0;
}
