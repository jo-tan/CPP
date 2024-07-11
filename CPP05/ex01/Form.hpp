a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it’s not).
• A constant grade required to sign it.
• And a constant grade required to execute it.
All these attributes are private, not protected.
The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
the following exceptions will be thrown if a form grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the form’s informations.

Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and turn in some tests to ensure everything works as expected.


/*?*/
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
    Form( const std::string& name, int gradeToSign );
    Form( const std::string& name, int gradeToSign, int gradeToExecute );
    Form( const Form& src );
    ~Form();

    Form&   operator=( const Form& rhs );

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;

    void        beSigned( const Bureaucrat& bureaucrat );

    /* ---------------- Exception Classes ---------------- */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif // FORM_HPP

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash",11);
        Form form("formName", 10);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}

/*other*/

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// classes

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
	// Constructors
		Form(void);
		Form(const Form &src);
		Form(int sign_grade, int exec_grade);
		Form(const std::string name);
		Form(const std::string name, int sign_grade, int exec_grade);

	// Deconstructors
		~Form();

	// Overloaded Operators
		Form &operator=(const Form &src);

	// Public Methods
		void beSigned(Bureaucrat &signer);
	// Getter
		const std::string getName(void)const;
		const std::string getIsSigned(void)const;
		bool getIsSignedBool(void)const;
		int getSignGrade(void)const;
		int getExecGrade(void)const;

	//Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a);