/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:11:25 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 05:28:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("Default AForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
	std::cout << GREY << "AForm: Default Constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &obj): _name(obj.getName() + "_copy"), _signed(false), _gradeToSign(obj.getGradeToSign()), _gradeToExecute(obj.getGradeToExecute()){
	std::cout << GREY << "AForm Copy Constructor called to copy " << obj.getName() <<
	" into " << this->getName() << RESET << std::endl;
	*this = obj;
}

AForm::AForm(int gradeToSign, int gradeToExecute): _name("Default AForm"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << GREY << "AForm: Constructor is called " << RESET << std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string &name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << GREY << "AForm: Constructor is called" << RESET << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << GREY << "AForm: Constructor is called" << RESET << std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm() {
	std::cout << GREY << "AForm: deconstructor is called" << RESET<< std::endl;
}

/*Overloaded Operators*/
AForm &AForm::operator=(const AForm &obj) {
	std::cout << GREY << "AForm Assignation operator called" << RESET << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

/*Public Function*/
void AForm::beSigned(Bureaucrat &signer) {
	if ((int)signer.getGrade() > this->getGradeToSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
	{
		this->_signed = true;
		std::cout << GREEN << this->getName() << RESET << " AForm was signed by " << YELLOW << signer.getName() << RESET << std::endl;
	}
	else
		std::cout << this->getName() << " AForm is already signed" << std::endl;
}

/*Getter*/
const std::string AForm::getName()const {
	return (this->_name);
}

bool AForm::getSigned()const {
	return (this->_signed);
}

int	AForm::getGradeToSign()const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute()const {
	return (this->_gradeToExecute);
}

/*exception*/
const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm Expection: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm Expection: Grade too low";
}

const char *AForm::NotSignedException::what() const throw() {
	return "AForm Expection: Form not signed";
}

const char *AForm::IsSignedException::what() const throw() {
	return "AForm Expection: Form is signed";
}

/*Overload ostream*/
std::ostream	&operator<<(std::ostream &o, AForm *a) {
	o << "AForm " << GREEN << a->getName() << RESET <<
	":\n\tsign-grade:\t" << CYAN << a->getGradeToSign() << RESET <<
	"\n\texec-grade:\t" << CYAN << a->getGradeToExecute() << RESET <<
	"\n\tis signed:\t" << CYAN << a->getSigned() << RESET << std::endl << std::endl;
	return (o);
}
