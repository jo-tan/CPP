/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:31:52 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 06:31:55 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>

class   Harl
{
    public:
        Harl();
        ~Harl();
        void	complain(std::string level);

    private:
        void	debug(void);
	    void	info(void);
	    void	warning(void);
	    void	error(void);
        void    invalid(void);
        void    call(std::string input, std::string level, void (Harl::*func)(void));
};

#endif
