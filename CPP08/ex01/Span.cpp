/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:47:16 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/08 19:04:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec)
{}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
  if (this != &other)
  {
    this->_N = other._N;
    this->_vec = other._vec;
  }
  return *this;
}

void Span::addNumber(int number)
{
  if (_vec.size() < _N)
    _vec.push_back(number);
  else
    throw std::length_error("Span is full");
}

int Span::shortestSpan() {
  if (_vec.size() < 2)
    throw std::length_error("Span is too short");
  std::vector<int> tmp(_vec);
  std::sort(tmp.begin(), tmp.end());
  int min = INT_MAX;
  for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
  {
    int diff = *(it + 1) - *it;
    if (diff < min)
      min = diff;
  }
  return min;
}

int Span::longestSpan() {
  if (_vec.size() < 2)
    throw std::length_error("Span is too short");
  std::vector<int> tmp(_vec);
  std::sort(tmp.begin(), tmp.end());
  return *(tmp.end() - 1) - *tmp.begin();
}

int Span::getNumber(int i) const {
  std::vector<int>::const_iterator it = _vec.begin();
  for (int j = 0; j < i; ++j){
    ++it;
  }
  int res = *it;
  return res;
}

void Span::addRanRange(unsigned int n) {
  if (_N < n )
    throw std::length_error("Span is too short");
  for (unsigned int i = 0; i < n; ++i)
  {
      _vec.push_back(i);
  }
  std::random_shuffle(_vec.begin(), _vec.end());
}