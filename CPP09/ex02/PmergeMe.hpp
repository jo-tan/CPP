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

/*You must create a program with these constraints:
• The name of the program is PmergeMe.
• Your program must be able to use a positive integer sequence as argument.
• Your program must use the merge-insert sort algorithm to sort the positive integer
sequence.

To clarify, yes, you need to use the Ford-Johnson algorithm.

• If an error occurs during program execution, an error message should be displayed
on the standard output.

You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.

It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

Here are some additional guidelines on the information you should display line by line
on the standard output:
• On the first line you must display an explicit text followed by the unsorted positive
integer sequence.
• On the second line you must display an explicit text followed by the sorted positive
integer sequence.
• On the third line you must display an explicit text indicating the time used by
your algorithm by specifying the first container used to sort the positive integer
sequence.
• On the last line you must display an explicit text indicating the time used by
your algorithm by specifying the second container used to sort the positive integer
sequence.

The format for the display of the time used to carry out your sorting
is free but the precision chosen must allow to clearly see the
difference between the two containers used.

Here is an example of a standard use:
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:
3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After:
79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>

The indication of the time is deliberately strange in this example.
Of course you have to indicate the time used to perform all your
operations, both the sorting part and the data management part.

Warning: The container(s) you used in the previous exercises are
forbidden here.

The management of errors related to duplicates is left to your
discretion.*/

#include <vector>
#include <algorithm>
#include <functional>

class PmergeMe {
private:
    static const int INSERTION_SORT_THRESHOLD = 16;

    template<typename T, typename Compare>
    static void insertionSort(std::vector<T>& arr, int left, int right, Compare comp) {
        for (int i = left + 1; i <= right; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= left && comp(key, arr[j])) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    template<typename T, typename Compare>
    static void merge(std::vector<T> &arr, int left, int mid, int right, Compare comp) {
        std::vector<T> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (comp(arr[i], arr[j])) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int p = 0; p < k; ++p) {
            arr[left + p] = temp[p];
        }
    }

    template<typename T, typename Compare>
    static void fordJohnsonSortHelper(std::vector<T> &arr, int left, int right, Compare comp) {
        if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
            insertionSort(arr, left, right, comp);
            return;
        }

        int mid = left + (right - left) / 2;
        fordJohnsonSortHelper(arr, left, mid, comp);
        fordJohnsonSortHelper(arr, mid + 1, right, comp);

        merge(arr, left, mid, right, comp);
    }

public:
    template<typename T, typename Compare>
    static void sort(std::vector<T> &arr, Compare comp) {
        fordJohnsonSortHelper(arr, 0, arr.size() - 1, comp);
    }
};


#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

template <typename T>
class PSort {
public:
    void sort(std::deque<T>& data) {
        if (data.empty()) return;
        quicksort(data, 0, data.size() - 1);
    }

private:
    void quicksort(std::deque<T>& data, int left, int right) {
        if (left < right) {
            int pivotIndex = partition(data, left, right);
            quicksort(data, left, pivotIndex - 1);
            quicksort(data, pivotIndex + 1, right);
        }
    }

    int partition(std::deque<T>& data, int left, int right) {
        T pivot = data[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (data[j] <= pivot) {
                ++i;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[right]);
        return i + 1;
    }
};
