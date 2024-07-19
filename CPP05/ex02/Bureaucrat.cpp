/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:11:52 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:57:36 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

<<<<<<< HEAD
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << GREY << "Bureaucrat: defualt contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << _grade << RESET << std::endl;
=======
/* Constructors & Destructors */
Bureaucrat::Bureaucrat(void): _name("unidentified") {
	this->_grade = 150;
	std::cout << YELLOW "[Bureaucrat] " RESET "New object called '" YELLOW << \
		this->_name << RESET "' with grade " YELLOW << this->_grade << RESET \
		"..." << std::endl;
>>>>>>> 37a2fdd9bf087d2d05d3537917363c1c3ffb6086
}

Bureaucrat::~Bureaucrat() {
	std::cout << GREY << "Bureaucrat: decontructor is called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name) {
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
	std::cout << GREY << "Bureaucrat: contructor is called" << RESET << std::endl;
	std::cout << "Bureaucrat Name: " << YELLOW << _name << RESET << " is created. Grade: ";
	std::cout << YELLOW << grade << RESET << std::endl;
	this->setGrade(grade);	
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) {
	std::cout << GREY << "Bureaucrat: copy contructor is called to copy" << RESET << std::endl;
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj) {
	std::cout << GREY << "Bureaucrat: assignation operator is called" << RESET << std::endl;
	if (this == &obj)
		return *this;
	this->_grade = obj.getGrade();
	return *this;
}

/*Setter & Getter*/
void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << YELLOW "[Bureaucrat] " RESET "New object called '" YELLOW << \
		this->_name << RESET "' with grade " YELLOW << this->_grade << RESET \
		"..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat.getName()) {
	*this = bureaucrat;
	std::cout << YELLOW "[Bureaucrat] " RESET "Copied object called '" YELLOW << \
		this->_name << RESET "'..." << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << BRED "[Bureaucrat] " RESET "Deleting object called '" YELLOW << \
		this->_name << RESET "'..." << std::endl;
}

/*public function*/
void	Bureaucrat::Increment() {
	std::cout << BLUE << "Increment function is called" << RESET << std::endl;
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << YELLOW "[Bureaucrat] " RESET "Grade incrementation succeeded. " << \
		"(from " YELLOW << oldGrade << RESET " to " YELLOW << this->_grade << RESET ")" << std::endl;
}

void	Bureaucrat::Decrement() {
	std::cout << BLUE << "Decrement function is called" << RESET << std::endl;
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << YELLOW "[Bureaucrat] " RESET "Grade decrementation succeeded. " << \
		"(from " YELLOW << oldGrade << RESET " to " YELLOW << this->_grade << RESET ")" << std::endl;
}

void	Bureaucrat::signForm(AForm &form) {
	if (form.isSigned()) {
		std::cout << YELLOW "[Bureaucrat] " YELLOW << this->_name << RESET " couldn't sign " << \
			YELLOW << form.getName() << RESET " because it's already signed!" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << YELLOW "[Bureaucrat] " YELLOW << this->_name << RESET " signed " \
			YELLOW << form.getName() << RESET "..." << std::endl;
	} catch (std::exception &exception) {
		std::cout << YELLOW "[Bureaucrat] " YELLOW << this->_name << RESET " couldn't sign " \
			YELLOW << form.getName() << RESET " because '" << YELLOW << exception.what() << \
			RESET << "'..." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << YELLOW "[Bureaucrat] " YELLOW << this->_name << RESET " executed " \
			YELLOW << form.getName() << RESET "..." << std::endl;
	} catch (std::exception &exception) {
		std::cout << YELLOW "[Bureaucrat] " YELLOW << this->_name << RESET " couldn't execute " \
			YELLOW << form.getName() << RESET " because '" << YELLOW << exception.what() << \
			RESET << "'..." << std::endl;
	}
}

/*Overload ostream*/
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << YELLOW << a->getName() << RESET <<
	":\n\tgrade: " << a->getGrade() << std::endl << std::endl;
	return (o);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

/* Overloaded operators */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat)
		this->_grade = bureaucrat.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << YELLOW "[Bureaucrat] " YELLOW << bureaucrat.getName() << \
		RESET ", bureaucrat grade " YELLOW << bureaucrat.getGrade() << RESET ".";
	return (out);
}
