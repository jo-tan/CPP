#include "PmergeMe.hpp"

int main() {
    std::vector<int> numbers;
    // Fill numbers with your large set of integers

    FordJohnsonSort::sort(numbers, std::less<int>());

    // Print or use the sorted numbers
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}