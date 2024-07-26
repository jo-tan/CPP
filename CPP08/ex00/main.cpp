/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:46:47 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/26 10:46:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"


int main()
{
  int vec_array[] = {1, 2, 3, 4, 5};
  std::vector<int> vec(vec_array, vec_array + sizeof(vec_array) / sizeof(int));

  int lst_array[] = {6, 7, 8, 9, 10};
  std::list<int> lst(lst_array, lst_array + sizeof(lst_array) / sizeof(int));
    try
    {
        std::cout << "Found " << *easyfind(vec, 3) << " in vector.\n";
        std::cout << "Found " << *easyfind(lst, 8) << " in list.\n";
        std::cout << "Found " << *easyfind(vec, 6) << " in vector.\n"; // This will throw an exception
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
