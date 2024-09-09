/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:11:26 by jo-tan            #+#    #+#             */
/*   Updated: 2024/08/19 18:11:28 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*You must create a program with these constraints:
• The program name is RPN.
• Your program must take an inverted Polish mathematical expression as an argu-
ment.
• The numbers used in this operation and passed as arguments will always be less
than 10. The calculation itself but also the result do not take into account this rule.
• Your program must process this expression and output the correct result on the
standard output.
• If an error occurs during the execution of the program an error message should be
displayed on the standard output.
• Your program must be able to handle operations with these tokens: "+ - / *".

You must use at least one container in your code to validate this
exercise.

You don’t need to manage the brackets or decimal numbers.

Here is an example of a standard use:
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>

Warning: The container(s) you used in the previous exercise are
forbidden here. The container(s) you used to validate this exercise
will not be usable for the rest of this module.*/

#ifndef RPN_HPP
# define RPN_HPP

# include <queue>
# include <stack>
# include <iostream>
# include <string> 
# include <stdexcept>
# include <limits>
# include <cstdlib>

class RPN{

    private:
        std::string _str;
        std::queue<std::string> _input;
        RPN();
        void parsing(const std::string _str);
        void AddOverflow(int a, int b);
        void SubOverflow(int a, int b);
        void MulOverflow(int a, int b);
    public:
        RPN(const std::string &_str);
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        int doMath();
};

#endif
