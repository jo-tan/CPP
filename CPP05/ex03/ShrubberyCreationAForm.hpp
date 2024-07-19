/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:21:01 by jo-tan           ###   ########.fr       */
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

class ShrubberyCreationAForm : public AForm {

private:
    const std::string   _target;
    ShrubberyCreationAForm();

public:
    ShrubberyCreationAForm(const std::string &target);
    ShrubberyCreationAForm(const ShrubberyCreationAForm &obj);
    ~ShrubberyCreationAForm();

    ShrubberyCreationAForm &operator=(ShrubberyCreationAForm &obj);
    
    std::string  getTarget()const;

    void        execute(const Bureaucrat &executor) const;
};
