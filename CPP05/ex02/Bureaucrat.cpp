
/*aForm*/
#include "Bureaucrat.hpp"

/* Constructors & Destructors */
Bureaucrat::Bureaucrat(void): _name("unidentified") {
	this->_grade = 150;
	std::cout << YELLOW "[Bureaucrat] " RESET "New object called '" YELLOW << \
		this->_name << RESET "' with grade " YELLOW << this->_grade << RESET \
		"..." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
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

/* Exceptions */
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high! (from highest 1 to lowest 150)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low! (from highest 1 to lowest 150)");
}

/* Functions */
void	Bureaucrat::incrementGrade(void) {
	int	oldGrade = this->_grade;

	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << YELLOW "[Bureaucrat] " RESET "Grade incrementation succeeded. " << \
		"(from " YELLOW << oldGrade << RESET " to " YELLOW << this->_grade << RESET ")" << std::endl;
}

void	Bureaucrat::decrementGrade(void) {
	int	oldGrade = this->_grade;

	this->_grade++;
	if (this->_grade > 150)
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

/* Getters */
const std::string	&Bureaucrat::getName(void) const {
	return (this->_name);
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