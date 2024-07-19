/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:16:45 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:38:13 by jo-tan           ###   ########.fr       */
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

AForm   *Intern::createPresidentialPardonForm(const std::string &target){
    return new PresidentialPardonForm(target);
}

AForm   *Intern::createRobotomyRequestForm(const std::string &target){
    return new RobotomyRequestForm(target);
}

AForm   *Intern::createShrubberyCreationForm(const std::string &target){
    return new ShrubberyCreationForm(target);
}


AForm   *Intern::makeForm(std::string name, const std::string &target) {
    
    if (target.empty()){
        throw std::invalid_argument("Error: Intern cannot create form without a target");
    }
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm  *(Intern::*formTable[3])(const std::string &target) = {
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createShrubberyCreationForm
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