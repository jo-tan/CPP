/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/19 18:08:35 by jo-tan           ###   ########.fr       */
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
#include <iomanip>
#include <algorithm>

#define DEBUG 1


class PmergeMe {

    private:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);

        static void sortPairs(std::vector<std::pair<int, int> >& pairs);
        static void insertRemaining(std::vector<int>& sorted, const std::vector<std::pair<int, int> >& pairs);
        static void binaryInsert(std::vector<int>& sorted, int value, int left, int right);
        static std::vector<int> generateInsertionSequence(int n);

        static void sortPairsDeq(std::deque<std::pair<int, int> >& pairs);
        static void insertRemainingDeq(std::deque<int>& sorted, const std::deque<std::pair<int, int> >& pairs);
        static void binaryInsertDeq(std::deque<int>& sorted, int value, int left, int right);
        static std::deque<int> generateInsertionSequenceDeq(int n);

    public:
        static void sortVector(std::vector<int>& arr);
        static void sortDeque(std::deque<int>& container);

};

double measureSortingTimeVector(std::vector<int>& container);
double measureSortingTimeDeque(std::deque<int>& container);

#endif