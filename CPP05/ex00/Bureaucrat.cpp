/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:45:27 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/14 16:47:13 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "defualt contructor called" << std::endl;
}

~Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(int grade, std::string name)
{}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this->obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	_name = obj._name;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}


void	Bureaucrat::UpGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::DownGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

