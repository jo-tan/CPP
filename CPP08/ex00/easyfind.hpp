** A tpp file is typically used to denote that the source file contains implementations
of templated methods (as opposed to putting the 
implementation in the header file).

A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as ex-
pected.

You don’t have to handle associative containers.
>> An AssociativeContainer is an ordered Container that provides fast lookup of objects based on keys.
An associative container supports unique keys
if it may contain at most one element for each key.
Otherwise, it supports equivalent keys. 

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif