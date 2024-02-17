/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:32:04 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:32:08 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl    harl;

    std::cout << "Test error cases:" << std::endl;
    harl.complain("");
    harl.complain("hi");
    std::cout << std::endl;
    std::cout << "Test normal cases:" << std::endl;
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    std::cout << std::endl;
    return 0;
}
