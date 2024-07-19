/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestAForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:33 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:20:17 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestAForm.hpp"

RobotomyRequestAForm::RobotomyRequestAForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestAForm::RobotomyRequestAForm(const RobotomyRequestAForm &cpy) : AForm(cpy), _target(cpy._target) {}

RobotomyRequestAForm::~RobotomyRequestAForm() {}

RobotomyRequestAForm &RobotomyRequestAForm::operator=(RobotomyRequestAForm &cpy) {
    (void)cpy;
    return *this;
}

void    RobotomyRequestAForm::execute(const Bureaucrat& executor) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (rand() % 2 == 0)
        std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
    else
        std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
}