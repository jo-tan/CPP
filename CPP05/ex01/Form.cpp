/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:10:45 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 05:21:09 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form(void): _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << GREY << "Form: Default Constructor called" << RESET << std::endl;
}

Form::Form(const Form &obj): _name(obj.getName() + "_copy"), _signed(false), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute())
{
	std::cout << GREY << "Form Copy Constructor called to copy " << obj.getName() <<
	" into " << this->getName() << RESET << std::endl;
	*this = obj;
}

Form::Form(int gradeToSign, int gradeToExecute): _name("Default Form"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << GREY << "Form: Constructor is called " << RESET << std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string &name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << GREY << "Form: Constructor is called" << RESET << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << GREY << "Form: Constructor is called" << RESET << std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form()
{
	std::cout << GREY << "Form: deconstructor is called" << RESET<< std::endl;
}

// Overloaded Operators
Form &Form::operator=(const Form &obj)
{
	std::cout << GREY << "Form Assignation operator called" << RESET << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

/*Public function*/
void Form::beSigned(Bureaucrat &signer)
{
	if (this->getSigned() == true)
		throw(Form::IsSignedException());
	if ((int)signer.getGrade() > this->getGradeToSign())
		throw(Form::GradeTooLowException());
	this->_signed = true;
	std::cout << GREEN << this->getName() << RESET << " Form was signed by " << YELLOW << signer.getName() << RESET << std::endl;
}


/*Getter*/
const std::string Form::getName()const {
	return (this->_name);
}

bool Form::getSigned()const {
	return (this->_signed);
}

int	Form::getGradeToSign()const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute()const {
	return (this->_gradeToExecute);
}

/*exception*/
const char *Form::GradeTooHighException::what() const throw() {
	return "Form Expection: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form Expection: Grade too low";
}

const char *Form::NotSignedException::what() const throw() {
	return "Form Expection: Form not signed";
}

const char *Form::IsSignedException::what() const throw() {
	return "Form Expection: Form is signed";
}

/*Overload ostream*/
std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << GREEN << a->getName() << RESET <<
	":\n\tsign-grade:\t" << CYAN << a->getGradeToSign() << RESET <<
	"\n\texec-grade:\t" << CYAN << a->getGradeToExecute() << RESET <<
	"\n\tis signed:\t" << CYAN << a->getSigned() << RESET << std::endl << std::endl;
	return (o);
}