/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:47:25 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/08 19:06:10 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "\n\033[35mTest a small span\033[0m" << std::endl;
    Span smallSpan(5);
    smallSpan.addNumber(1);
    smallSpan.addNumber(3);
    smallSpan.addNumber(5);
    smallSpan.addNumber(7);
    smallSpan.addNumber(9);

    std::cout << "Small span shortest span: " << smallSpan.shortestSpan() << std::endl;
    std::cout << "Small span longest span: " << smallSpan.longestSpan() << std::endl;

    std::cout << "\n\033[35mTest a large span\033[0m" << std::endl;
    Span largeSpan(12000);
    for (int i = 0; i < 12000; ++i)
    {
        largeSpan.addNumber(i);
    }

    std::cout << "Large span shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Large span longest span: " << largeSpan.longestSpan() << std::endl;

    std::cout << "\n\033[35mTest range random span\033[0m" << std::endl;
    Span randSpan(200);
    try {
        randSpan.addRanRange(200);
        /*To check random numbers within range 0-199*/
        for (int i = 0; i < 200; ++i)
        {
            std::cout << randSpan.getNumber(i) << " ";
            if (i != 0 && i % 20 == 0)
            {
                std::cout << std::endl;    
            }
        }
        std::cout << std::endl;
        
        std::cout << "Large random span shortest span: " << randSpan.shortestSpan() << std::endl;
        std::cout << "Large random span longest span: " << randSpan.longestSpan() << std::endl;
    } catch  (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    

    std::cout << "\n\033[35mTest a single span (should throw exception)\033[0m" << std::endl;
    Span singleSpan(1);
    singleSpan.addNumber(1);

    try
    {
        std::cout << "Single span shortest span: " << singleSpan.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Single span longest span: " << singleSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n\033[35mTest an empty span (should throw exception)\033[0m" << std::endl;
    Span emptySpan(0);

    try
    {
        emptySpan.addNumber(1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
