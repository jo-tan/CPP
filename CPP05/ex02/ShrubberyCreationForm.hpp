/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:13:28 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:30:00 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

#define ASCII_TREE "\
\n#########################################  \
\n                          \\ | /           \
\n                        - (___) -          \
\n                          / | \\           \
\n                                           \
\n                                           \
\n                                           \
\n              ,@@@@@@@,                    \
\n      ,,,.   ,@@@@@@/@@,  .oo8888o.        \
\n   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      \
\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'  \
\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   \
\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'    \
\n   `&%\\ ` /%&'    |.|        \\ '|8'      \
\n       |o|        | |         | |          \
\n       |.|        | |         | |          \
\n /,__\\/ ._\\//_/__/  ,\\_///__\\/.  \\_// \
\n#########################################  \
"

class ShrubberyCreationForm : public AForm {

private:
    const std::string   _target;
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
    
    std::string  getTarget()const;
    void        execute(const Bureaucrat& executor) const;

};
