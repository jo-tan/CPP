/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:45:27 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/12 18:25:38 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << GREY << "Bureaucrat: defualt contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << _grade << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "Bureaucrat: decontructor is called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name)
{
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150)
{
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);	
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	std::cout << GREY << "Bureaucrat: copy contructor is called to copy" << RESET << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	std::cout << GREY << "Bureaucrat: assignation operator is called" << RESET << std::endl;
	if (this == &obj)
		return *this;
	this->_grade = obj.getGrade();
	return *this;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::Increment()
{
	std::cout << BLUE << "Increment function is called" << RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
	std::cout << YELLOW << this->getName() << RESET << "'s new grade: " << YELLOW << this->getGrade() << RESET << std::endl;
}

void	Bureaucrat::Decrement()
{
	std::cout << BLUE << "Decrement function is called" << RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
	std::cout << YELLOW << this->getName() << RESET << "'s new grade: " << YELLOW << this->getGrade() << RESET << std::endl;
}

void	Bureaucrat::signForm(Form c)
{
	if (c.getSigned() == true)
	{
		std::cout << YELLOW << this->getName() << RESET << "signed" <<
		GREEN << c.getName() << RESET << std::endl;
	}
	else
	{
		std::cout << YELLOW << this->getName() << RESET << " couldn't signed" <<
		GREEN << c.getName() << RESET << "because " <<
		YELLOW << this->getName() << RESET << "'s permission level(" << this->getGrade() <<
		") cannot sign " << GREEN << c.getName() << RESET <<
		"(" << c.getGradeToExecute() << ")" << std::endl;
	}
	/*If the form got signed,
	it will print something like:
	<bureaucrat> signed <form>
	Otherwise, it will print something like:
	<bureaucrat> couldn’t sign <form> because <reason>.*/
}

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade();
	return (o);
}