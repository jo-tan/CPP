/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:29 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:12:30 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

unsigned int PmergeMe::jacobsthal(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Vector implementation
void PmergeMe::sortVector(std::vector<int>& container) {
    mergeInsertionSortVector(container, container.begin(), container.end());

    size_t n = container.size();
    unsigned int jacobsthalIdx = 3;
    size_t prev = 1;
    size_t curr = 3;

    while (curr < n) {
        for (size_t i = prev; i < curr && i + curr < n; ++i) {
            std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.begin() + curr, container[i + curr]);
            int value = container[i + curr];
            container.erase(container.begin() + i + curr);
            container.insert(pos, value);
        }
        prev = curr;
        curr = jacobsthal(++jacobsthalIdx);
    }

    for (size_t i = prev; i < n - 1; ++i) {
        std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.begin() + i + 1, container[i + 1]);
        int value = container[i + 1];
        container.erase(container.begin() + i + 1);
        container.insert(pos, value);
    }
}

void PmergeMe::insertionSortVector(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator i = begin + 1; i != end; ++i) {
        int key = *i;
        std::vector<int>::iterator j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            if (j == begin) break;
        --j;
        }
        *(j + 1) = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>::iterator begin, std::vector<int>::iterator mid, std::vector<int>::iterator end) {
    std::vector<int> temp(begin, end);
    std::vector<int>::iterator left = temp.begin();
    std::vector<int>::iterator right = left + (mid - begin);
    std::vector<int>::iterator target = begin;

    while (left < right && right < temp.end()) {
        if (*left <= *right) {
            *target = *left;
            ++left;
        } else {
            *target = *right;
            ++right;
        }
        ++target;
    }

    while (left < right) {
        *target = *left;
        ++left;
        ++target;
    }

    while (right < temp.end()) {
        *target = *right;
        ++right;
        ++target;
    }
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& container, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (end - begin <= 1) return;

    std::vector<int>::iterator mid = begin + (end - begin) / 2;
    mergeInsertionSortVector(container, begin, mid);
    mergeInsertionSortVector(container, mid, end);

    if (end - begin <= 16) {
        insertionSortVector(begin, end);
    } else {
        mergeVector(begin, mid, end);
    }
}

// Deque implementation
void PmergeMe::sortDeque(std::deque<int>& container) {
    mergeInsertionSortDeque(container, container.begin(), container.end());

    size_t n = container.size();
    unsigned int jacobsthalIdx = 3;
    size_t prev = 1;
    size_t curr = 3;

    while (curr < n) {
        for (size_t i = prev; i < curr && i + curr < n; ++i) {
            std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.begin() + curr, container[i + curr]);
            int value = container[i + curr];
            container.erase(container.begin() + i + curr);
            container.insert(pos, value);
        }
        prev = curr;
        curr = jacobsthal(++jacobsthalIdx);
    }

    for (size_t i = prev; i < n - 1; ++i) {
        std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.begin() + i + 1, container[i + 1]);
        int value = container[i + 1];
        container.erase(container.begin() + i + 1);
        container.insert(pos, value);
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
    for (std::deque<int>::iterator i = begin + 1; i != end; ++i) {
        int key = *i;
        std::deque<int>::iterator j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            if (j == begin) break;
            --j;
    }
        *(j + 1) = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>::iterator begin, std::deque<int>::iterator mid, std::deque<int>::iterator end) {
    std::deque<int> temp(begin, end);
    std::deque<int>::iterator left = temp.begin();
    std::deque<int>::iterator right = left + (mid - begin);
    std::deque<int>::iterator target = begin;

    while (left < right && right < temp.end()) {
        if (*left <= *right) {
            *target = *left;
            ++left;
        } else {
            *target = *right;
            ++right;
        }
        ++target;
    }

    while (left < right) {
        *target = *left;
        ++left;
        ++target;
    }

    while (right < temp.end()) {
        *target = *right;
        ++right;
        ++target;
    }
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& container, std::deque<int>::iterator begin, std::deque<int>::iterator end) {
    if (end - begin <= 1) return;

    std::deque<int>::iterator mid = begin + (end - begin) / 2;
    mergeInsertionSortDeque(container, begin, mid);
    mergeInsertionSortDeque(container, mid, end);

    if (end - begin <= 16) {
        insertionSortDeque(begin, end);
    } else {
        mergeDeque(begin, mid, end);
    }
}

double measureSortingTimeVector(std::vector<int>& container) {
    clock_t start = clock();
    PmergeMe::sortVector(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000.0);
}

double measureSortingTimeDeque(std::deque<int>& container) {
    clock_t start = clock();
    PmergeMe::sortDeque(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000.0);
}