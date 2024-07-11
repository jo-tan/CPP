#pragma once
# include <iostream>
# include <string>
# include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;241m"

class AForm;

class Bureaucrat
{
	private:
		const	std::string _name;
		int		_grade;
		void	setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(int grade, const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		
		std::string	getName()const;
		int			getGrade()const;
		void		Increment();
		void		Decrement();
		void		signForm(Form f);

		/*Exception Class*/
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw(){return "Grade too high! (Highest: 1)";}
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw(){return "Grade too low! (Lowest: 150)";}
		};
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

/*aForm*/
/*
 * Bureaucrat doesn't know what Form is because it hasn't been declared yet.
 * We then have to forward the declaration of the Form class.
 * This will inform the compiler that there is class named Form that will
 * be defined later.
*/
/*class AForm;

class Bureaucrat {
	
	private:
		const std::string	_name;
		int					_grade;

	public:
		/* Constructors & Destructors */
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat(void);

		/* Exceptions */
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		/* Functions */
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		/* Getters */
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		/* Overloaded operators */
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

*/