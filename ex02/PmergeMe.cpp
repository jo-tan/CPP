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

    // Step 5: Insert remaining elements
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

    std::vector<bool> inserted(pairs.size(), false);
    
    for (size_t i = 0; i < insertionSequence.size(); ++i) {
        int index = insertionSequence[i];
        if (index < static_cast<int>(pairs.size())) {
            if (DEBUG){
                // Debug: Print the element being inserted
                std::cout << "Inserting smaller element from pairs[" << index << "] = " << pairs[index].first << std::endl;
            }
            binaryInsert(sorted, pairs[index].first, 0, sorted.size() - 1);
            inserted[index] = true;
        }
    }

    for (size_t i = 0; i < pairs.size(); ++i){
        if (!inserted[i]){
            binaryInsert(sorted, pairs[i].first, 0, sorted.size() - 1);
            inserted[i] = true;
        }
    }
}

void PmergeMe::binaryInsert(std::vector<int>& sorted, int value, int left, int right) {

    if (DEBUG){
       // Debug: Print the sorted array before insertion
        std::cout << "Before inserting " << value << ": ";
        for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl; 
    }
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    sorted.insert(sorted.begin() + left, value);

    if (DEBUG){
       // Debug: Print the sorted array after insertion
        std::cout << "After inserting " << value << ": ";
        for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl; 
    }
}

std::vector<int> PmergeMe::generateInsertionSequence(int n) {
    std::vector<int> Jsequence;
    int j0 = 1, j1 = 3;
    if (n > 0) Jsequence.push_back(j0);
    if (n > 1) Jsequence.push_back(j1);
    int currSequenceIndex = 2;
    
    while (true){
        int jNext = j1 + 2 * j0;
        if (jNext > n)
            break;
        Jsequence.push_back(jNext);
        j0 = j1;
        j1 = jNext;
        currSequenceIndex++;
    }

    if (DEBUG){
        // Debug: Print the generated insertion sequence
        std::cout << "Insertion Sequence: ";
        for (std::vector<int>::iterator it = Jsequence.begin(); it != Jsequence.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return Jsequence;
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
    int power = 2;
    int lastGroupStart = 1;

    while (lastGroupStart <= n) {
        for (int i = lastGroupStart; i < lastGroupStart + power / 2 && i <= n; ++i) {
            sequence.push_back(i);
        }
        lastGroupStart += power / 2;
        power *= 2;
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