/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:16:54 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:34:29 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

private:
    AForm *createPresidentialPardonForm(const std::string &target);
    AForm *createRobotomyRequestForm(const std::string &target);
    AForm *createShrubberyCreationForm(const std::string &target);
    
public:
    Intern();
    Intern(const Intern &obj);
    ~Intern();
    Intern &operator=(const Intern &obj);

    AForm *makeForm(std::string name, const std::string &target);
};
