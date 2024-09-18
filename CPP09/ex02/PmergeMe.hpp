/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:12:21 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <iomapip>


class PmergeMe {
public:
    static void sortVector(std::vector<int>& container);
    static void sortDeque(std::deque<int>& container);

private:
    static void insertionSortVector(std::vector<int>& container, std::vector<int>::iterator begin, std::vector<int>::iterator end);
    static void mergeVector(std::vector<int>& container, std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end);
    static void mergeInsertionSortVector(std::vector<int>& container, std::vector<int>::iterator begin, std::vector<int>::iterator end);

    static void insertionSortDeque(std::deque<int>& container, std::deque<int>::iterator begin, std::deque<int>::iterator end);
    static void mergeDeque(std::deque<int>& container, std::deque<int>::iterator begin, std::deque<int>::iterator mid, std::deque<int>::iterator end);
    static void mergeInsertionSortDeque(std::deque<int>& container, std::deque<int>::iterator begin, std::deque<int>::iterator end);

    static unsigned int jacobsthal(unsigned int n);
};

double measureSortingTimeVector(std::vector<int>& container);
double measureSortingTimeDeque(std::deque<int>& container);

#endif // PMERGEME_HPP