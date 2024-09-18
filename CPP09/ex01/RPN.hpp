/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:11:26 by jo-tan            #+#    #+#             */
/*   Updated: 2024/09/10 10:29:21 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        
        void parsing(const std::string _str);
        void AddOverflow(int a, int b);
        void SubOverflow(int a, int b);
        void MulOverflow(int a, int b);
        
    public:
        RPN(const std::string &_str);
        ~RPN();
        int doMath();
};

#endif
