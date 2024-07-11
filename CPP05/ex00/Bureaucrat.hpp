/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:17:25 by jo-tan            #+#    #+#             */
/*   Updated: 2024/04/14 16:47:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat
{
	private:
		const	std::string _name;
		int		_grade;
		void	setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		
		std::string	getName()const;
		int			getGrade()const;
		void		UpGrade();
		void		DownGrade();


		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw(){
					return "Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw(){
					return "Grade too low!";
				}
		};
};


/*?*/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

    Bureaucrat();

public:
    Bureaucrat( const std::string& name, int grade );
    Bureaucrat( const Bureaucrat& src );
    ~Bureaucrat();

    Bureaucrat& operator=( const Bureaucrat& rhs );

    std::string getName() const;
    int         getGrade() const;

    void        incrementGrade();
    void        decrementGrade();

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

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif // BUREAUCRAT_HPP

/*other way*/
// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class Bureaucrat
{
	private:
		const std::string _name;
		size_t _grade;
		// Setter
		void setGrade(int grade);

	public:
	// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);

	// Deconstructors
		~Bureaucrat();

	// Overloaded Operators
		Bureaucrat &operator=(const Bureaucrat &src);

	// Public Methods
		void incrementGrade(void);
		void decrementGrade(void);
	// Getter
		const std::string getName(void)const;
		size_t getGrade(void)const;

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
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);