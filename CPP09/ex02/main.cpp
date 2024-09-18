/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:12:00 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:12:01 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

class InputError : public std::runtime_error {
public:
    InputError(const std::string& msg) : std::runtime_error(msg) {}
};

int validateAndConvert(const std::string& input) {

    if (input.empty()){
        throw InputError("no data set");
    }
    std::istringstream iss(input);
    long long num;
    
    if (!(iss >> num) || !iss.eof()) {
        throw InputError("not a valid number: " + input);
    }
    
    if (num < 0) {
        throw InputError("negative number: " + input);
    }
    
    if (num > INT_MAX) {
        throw InputError("number too large: " + input);
    }
    
    return static_cast<int>(num);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    try {
        for (int i = 1; i < argc; ++i) {
            int num = validateAndConvert(argv[i]);
            vec.push_back(num);
            deq.push_back(num);
        }
        std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); ++i){
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        double vector_time = measureSortingTimeVector(vec);
        double deque_time = measureSortingTimeDeque(deq);

        std::cout << "After: ";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
                  << vector_time << " ms" << std::endl;
        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " 
                  << deque_time << " ms" << std::endl;
    }
    catch (const InputError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}