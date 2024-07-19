/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:16:45 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:57:43 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &obj){
    *this = obj;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &obj) {
    (void)obj;
    return (*this);
}

AForm   *Intern::createPresidentialPardonAForm(const std::string &target){
    return new PresidentialPardonAForm(target);
}

AForm   *Intern::createRobotomyRequestAForm(const std::string &target){
    return new RobotomyRequestAForm(target);
}

AForm   *Intern::createShrubberyCreationAForm(const std::string &target){
    return new ShrubberyCreationAForm(target);
}


AForm   *Intern::makeForm(std::string name, const std::string &target) {
    
    if (target.empty()){
        throw std::invalid_argument("Error: Intern cannot create form without a target");
    }
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm  *(Intern::*formTable[3])(const std::string &target) = {
        &Intern::createPresidentialPardonAForm,
        &Intern::createRobotomyRequestAForm,
        &Intern::createShrubberyCreationAForm
    };
    for (int i(0); i < 3; i++) {
        if (name == formNames[i]) {
            AForm *form = (this->*formTable[i])(target);
            std::cout << "Intern creates " << name << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create " << GREEN << name << RESET << " form because the form name is incorrect" << std::endl;
    return NULL;
}