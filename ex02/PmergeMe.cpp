/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:29 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/19 18:26:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src){
    (void) src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src){
    (void) src;
    return *this;
}

// Vector implementation
void PmergeMe::sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Step 1: Group elements into pairs
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }

    // Handle odd-length input
    int extraElement = -1;
    if (arr.size() % 2 != 0) {
        extraElement = arr.back();
    }

    // Step 2 & 3: Sort the pairs based on their larger elements
    sortPairs(pairs);

    // Step 4: Create the sorted sequence S with the larger elements
    std::vector<int> sorted;
    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted.push_back(pairs[i].second);
    }

    // Insert the element paired with the smallest element of S
    sorted.insert(sorted.begin(), pairs[0].first);

    // Step 5: Insert remaining elements using Jacobsthal sequence
    insertRemaining(sorted, pairs);

    // Handle odd-length input
    if (extraElement != -1) {
        binaryInsert(sorted, extraElement, 0, sorted.size() - 1);
    }

    // Copy sorted result back to input array
    arr = sorted;
}

struct ComparePairs {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second;
    }
};

void PmergeMe::sortPairs(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) return;

    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    if (DEBUG){
        std::cout << "\033[33mDividing\033[0m\nLeft: ";
        for (std::vector<std::pair<int, int> >::iterator it = left.begin(); it != left.end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << " | Right: ";
        for (std::vector<std::pair<int, int> >::iterator it = right.begin(); it != right.end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;
    }

    sortPairs(left);
    sortPairs(right);

    if (DEBUG){
        std::cout << "\033[33mMerging\033[0m\nLeft: ";
        for (std::vector<std::pair<int, int> >::iterator it = left.begin(); it != left.end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << " | Right: ";
        for (std::vector<std::pair<int, int> >::iterator it = right.begin(); it != right.end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;

    }
    
    std::vector<std::pair<int, int> > merged;
    merged.reserve(pairs.size());
    std::merge(left.begin(), left.end(), right.begin(), right.end(), 
               std::back_inserter(merged), ComparePairs());

    if (DEBUG){
        std::cout << "\033[33mMerged\033[0m: ";
        for (std::vector<std::pair<int, int> >::iterator it = merged.begin(); it != merged.end(); ++it) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
        std::cout << std::endl;
    }
    
    pairs = merged;
}

void PmergeMe::insertRemaining(std::vector<int>& sorted, const std::vector<std::pair<int, int> >& pairs) {
   std::vector<int> insertionSequence = generateInsertionSequence(pairs.size() - 1);
    
    for (size_t i = 0; i < insertionSequence.size(); ++i) {
        int index = insertionSequence[i];
        if (index < static_cast<int>(pairs.size())) {
            if (DEBUG) {
                std::cout << "Inserting smaller element from pairs[" << index << "] = " << pairs[index].first << std::endl;
            }
            binaryInsert(sorted, pairs[index].first, 0, sorted.size() - 1);
        }
    }
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

void PmergeMe::binaryInsert(std::vector<int>& sorted, int value, int left, int right) {

   while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] == value) {
            sorted.insert(sorted.begin() + mid, value);
            return;
        } else if (sorted[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    sorted.insert(sorted.begin() + left, value);

    if (DEBUG) {
        std::cout << "After inserting " << value << ": ";
        for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> PmergeMe::generateInsertionSequence(int n) {
    std::vector<int> sequence;
    sequence.push_back(1);  // Start with 1

    int j = 3; // Start with the 3rd Jacobsthal number (3)
    int prev = 1;
    int curr = 3;

    while (curr <= n) {
        // Add elements in reverse order from curr down to (prev+1)
        for (int i = curr; i > prev; --i) {
            if (i <= n) sequence.push_back(i);
        }
        
        // Move to the next Jacobsthal number
        int next = jacobsthal(j + 1);
        prev = curr;
        curr = next;
        ++j;
    }

    // Add any remaining elements
    for (int i = prev + 1; i <= n; ++i) {
        sequence.push_back(i);
    }

    if (DEBUG) {
        std::cout << "Insertion Sequence: ";
        for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return sequence;
}

// Deque implementation
void PmergeMe::sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // Step 1: Group elements into pairs
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        } else {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
    }

    // Handle odd-length input
    int extraElement = -1;
    if (arr.size() % 2 != 0) {
        extraElement = arr.back();
    }

    // Step 2 & 3: Sort the pairs based on their larger elements
    sortPairsDeq(pairs);

    // Step 4: Create the sorted sequence S with the larger elements
    std::deque<int> sorted;
    for (size_t i = 0; i < pairs.size(); ++i) {
        sorted.push_back(pairs[i].second);
    }

    // Insert the element paired with the smallest element of S
    sorted.insert(sorted.begin(), pairs[0].first);

    // Step 5: Insert remaining elements
    insertRemainingDeq(sorted, pairs);

    // Handle odd-length input
    if (extraElement != -1) {
        binaryInsertDeq(sorted, extraElement, 0, sorted.size() - 1);
    }

    // Copy sorted result back to input array
    arr = sorted;
}

void PmergeMe::sortPairsDeq(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) return;

    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    sortPairsDeq(left);
    sortPairsDeq(right);

    std::deque<std::pair<int, int> > merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), 
               std::back_inserter(merged), ComparePairs());
    pairs.swap(merged);
}

void PmergeMe::insertRemainingDeq(std::deque<int>& sorted, const std::deque<std::pair<int, int> >& pairs) {
    std::deque<int> insertionSequence = generateInsertionSequenceDeq(pairs.size() - 1);
    
    for (size_t i = 0; i < insertionSequence.size(); ++i) {
        int index = insertionSequence[i];
        if (index < static_cast<int>(pairs.size())) {
            if (DEBUG) {
                std::cout << "Inserting smaller element from pairs[" << index << "] = " << pairs[index].first << std::endl;
            }
            binaryInsertDeq(sorted, pairs[index].first, 0, sorted.size() - 1);
        }
    }
}

void PmergeMe::binaryInsertDeq(std::deque<int>& sorted, int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] == value) {
            sorted.insert(sorted.begin() + mid, value);
            return;
        } else if (sorted[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    sorted.insert(sorted.begin() + left, value);
}

std::deque<int> PmergeMe::generateInsertionSequenceDeq(int n) {
    std::deque<int> sequence;
    sequence.push_back(1);

    int j = 3;
    int prev = 1;
    int curr = 3;

    while (curr <= n) {
        for (int i = curr; i > prev; --i) {
            if (i <= n) sequence.push_back(i);
        }
        int next = jacobsthal(j + 1);
        prev = curr;
        curr = next;
        ++j;
    }

    //add remaining numbers
    for (int i = prev + 1; i <= n; ++i) {
        sequence.push_back(i);
    }
    return sequence;
}


double measureSortingTimeVector(std::vector<int>& container) {
    clock_t start = clock();
    PmergeMe::sortVector(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000.0);
}

double measureSortingTimeDeque(std::deque<int>& container) {
    clock_t start = clock();
    (void) container;
    PmergeMe::sortDeque(container);
    clock_t end = clock();
    return static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000.0);
}