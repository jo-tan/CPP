/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:47:06 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/08 18:32:12 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

class Span
{ 
  private:
    unsigned int _N;
    std::vector<int> _vec;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    int getNumber(int i) const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
      while (begin != end)
      {
        addNumber(*begin);
        ++begin;
      }
    }

};

#endif
