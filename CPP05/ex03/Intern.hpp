/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:16:54 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:41:02 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationAForm.hpp"
#include "RobotomyRequestAForm.hpp"
#include "PresidentialPardonAForm.hpp"

class Intern {

private:
    AForm *createPresidentialPardonAForm(const std::string &target);
    AForm *createRobotomyRequestAForm(const std::string &target);
    AForm *createShrubberyCreationAForm(const std::string &target);
    
public:
    Intern();
    Intern(const Intern &obj);
    ~Intern();
    Intern &operator=(const Intern &obj);

    AForm *makeForm(std::string name, const std::string &target);
};
