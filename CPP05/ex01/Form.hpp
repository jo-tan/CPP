#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
    	const std::string   _name;
    	bool                _signed;
    	const int           _gradeToSign;
    	const int           _gradeToExecute;



	public:
		Form();
		Form(const Form &src);
		Form(int gradeToSign, int gradeToExecute);
		Form(const std::string &name);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		
		~Form();

    	Form &operator=(const Form &obj);

    	const std::string getName() const;
    	bool getSigned() const;
    	int getGradeToSign() const;
    	int getGradeToExecute() const;

    	void beSigned(Bureaucrat &signer);

    /* Exception Class*/
    class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw() { return "Form Expection: Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw() { return "Form Expection: Grade too low"; }
    };
};

std::ostream &operator<<(std::ostream &o, Form *a);