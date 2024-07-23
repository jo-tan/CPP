Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.
Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.
Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.

#include <iostream>

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void printElement(T const & element) {
    std::cout << element << std::endl;
}

template <typename T, typename F>
void iter(T* array, size_t size, F function) {
    for (size_t i = 0; i < size; ++i) {
        function(array[i]);
    }
}
#endif