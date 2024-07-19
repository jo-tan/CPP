/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:58 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:19:45 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonAForm.hpp"

PresidentialPardonAForm::PresidentialPardonAForm(const std::string& target) : AForm("PresidentialPardonAForm",25,5), _target(target) {}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm &obj) : AForm(obj), _target(obj._target) {}

PresidentialPardonAForm::~PresidentialPardonAForm() {}

PresidentialPardonAForm &PresidentialPardonAForm::operator=(const PresidentialPardonAForm &obj) {
    (void)obj;
    return *this;
}

void    PresidentialPardonAForm::execute(const Bureaucrat& executor) const {
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}