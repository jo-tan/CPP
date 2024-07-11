Since you now have basic forms, it’s time to make a few more that actually do some-
thing.
In all cases, the base class Form must be an abstract class, and therefore should be
renamed AForm. Keep in mind the form’s attributes need to remain private and that
they are in the base class.
Add the following concrete classes:
• ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
• RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.

Now, add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an appropriate excep-
tion.
Whether you want to check the requirements in every concrete class or in the base
class (then call another function to execute the form) is up to you. However, one way is
prettier than the other one.
Lastly, add the executeForm(AForm const & form) member function to the Bureau-
crat. It must attempt to execute the form. If it’s successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.
Implement and turn in some tests to ensure everything works as expected.


/*?*/
#include "Form.hpp"

Form::Form( const std::string& name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if ( gradeToSign < 1 || gradeToExecute < 1 )
        throw Form::GradeTooHighException();
    if ( gradeToSign > 150 || gradeToExecute > 150 )
        throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : _name( src.getName() ), _gradeToSign( src.getGradeToSign() ), _gradeToExecute( src.getGradeToExecute() ) {}

Form::~Form() {}

Form&   Form::operator=( const Form& rhs ) {
    if ( this != &rhs )
        _signed = rhs.getSigned();
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool   Form::getSigned() const {
    return _signed;
}

int   Form::getGradeToSign() const {
    return _gradeToSign;
}

int   Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if ( bureaucrat.getGrade() > _gradeToSign ) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream&   operator<<( std::ostream &o, const Form& rhs ) {
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;;
    return o;
}

//header

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

    Form();

public:
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    Form( const Form& src );
    virtual    ~Form();

    Form&   operator=( const Form& rhs );

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned( const Bureaucrat& bureaucrat );

    virtual void        execute( const Bureaucrat& executor ) const = 0;

    /* ---------------- Exception Classes ---------------- */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
    class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form not signed"; }
    };
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif // FORM_HPP

/*aForm*/
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

/*
 * Form doesn't know what Bureaucrat is because it hasn't been declared yet.
 * We then have to forward the declaration of the Bureaucrat class.
 * This will inform the compiler that there is class named Bureaucrat that will
 * be defined later.
*/
class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		const int			_requiredSign;
		const int			_requiredExec;
		bool				_signed;

	public:
		/* Constructors & Destructors */
		AForm(void);
		AForm(const std::string &name, const int requiredSign, const int requiredExec);
		AForm(const AForm &form);
		~AForm(void);

		/* Exceptions */
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class UnsignedFormException: public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		/* Functions */
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	executeRequirements(Bureaucrat const &executor) const = 0;

		/* Getters */
		const std::string	&getName(void) const;
		const int			&getRequiredSign(void) const;
		const int			&getRequiredExec(void) const;
		bool				isSigned(void) const;

		/* Overloaded operators */
		AForm	&operator=(const AForm &form);

};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif