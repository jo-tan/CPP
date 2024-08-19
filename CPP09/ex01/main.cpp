/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:11:14 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:11:16 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc == 2){
        try{
            RPN input(argv[1]);
            std::cout << input.doMath() << std::endl;
        } catch (const std::exception &e){
            std::cout << e.what() << std::endl;
            return (1);
        }
    } else {
        std::cerr << "Input Error: Wrong Argument Count.\nUsage: ./RPN <input with quotes>" << std::endl;
        return (1);
    }
    return (0);
}
