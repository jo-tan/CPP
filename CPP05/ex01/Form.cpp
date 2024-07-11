#include "Form.hpp"

// Constructors
Form::Form(void): _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form: Default Constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _signed(false), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int gradeToSign, int gradeToExecute): _name("Default Form"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form: Constructor is called " << std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string &name): _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form: Constructor is called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form: Constructor is called" << std::endl;
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
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &obj)
		return *this;

	//nothing to assign in this class
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getGradeToSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string Form::getName()const
{
	return (this->_name);
}

bool Form::getSigned()const
{
	return (this->_signed);
}

int	Form::getGradeToSign()const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute()const
{
	return (this->_gradeToExecute);
}

/*ostream Overload*/
std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << YELLOW << a->getName() << RESET <<
	":\n\tsign-grade:\t" << YELLOW << a->getGradeToSign() << RESET <<
	"\n\texec-grade:\t" << YELLOW << a->getGradeToExecute() << RESET <<
	"\n\tis signed:\t" << YELLOW << a->getSigned() << RESET <<
	std::endl;
	return (o);
}