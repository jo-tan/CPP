/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:17:25 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 04:01:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;241m"

class Form;

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
		void		signForm(Form &f);

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