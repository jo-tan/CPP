/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:48:11 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/08 18:01:20 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <cassert>
#include <list>

int main()
{
  MutantStack<int> mstack;
  std::list<int> lst;

  std::cout << "\033[35mAdd 2 number in stack and list and reomve first elements\033[0m" << std::endl;
  mstack.push(5); // add 5 to stack
  mstack.push(17); // add 17 to stack
  lst.push_back(5);
  lst.push_back(17);
  std::cout << "top element: " << mstack.top() << "\t" << lst.back() << std::endl; // check the top element in stack
  mstack.pop(); // remove top element in stack
  lst.pop_back();
  std::cout << "size: " << mstack.size() << "\t" << lst.size() << std::endl;

  std::cout << "\033[35m\nAdd 5 number in stack and list\033[0m" << std::endl;
  mstack.push(3);
  mstack.push(99);
  mstack.push(737);
  mstack.push(42);
  mstack.push(0);

  lst.push_back(3);
  lst.push_back(99);
  lst.push_back(737);
  lst.push_back(42);
  lst.push_back(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  std::cout << "\033[35m\nIn stack\033[0m" << std::endl;
  for (;it != ite; ++it)
  {
    std::cout << *it << std::endl;
  }

  std::cout << "\033[35m\nIn list\033[0m" << std::endl;
  for (std::list<int>::iterator lstit = lst.begin() ; lstit != lst.end(); ++lstit)
  {
    std::cout << *lstit << std::endl;
  }
  std::cout << "\033[35m\nTest expections\033[0m" << std::endl;
  std::stack<int> s(mstack);

  MutantStack<int> nstack;
  assert(nstack.size() == 0);
  assert(nstack.empty() == true);

  MutantStack<int> lstack;
  lstack.push(5);
  assert(lstack.top() == 5);
  assert(lstack.size() == 1);

  try {
    lstack.pop();
    lstack.pop();
    lstack.pop();
    assert(false);  // Should not reach here
  } catch (const std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
try {
    int top = lstack.top();
    (void)top;
    assert(false);  // Should not reach here
  } catch (const std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}
