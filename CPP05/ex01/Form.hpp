/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:10:36 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 05:22:06 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
	class NotSignedException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
	class IsSignedException : public std::exception {
        public:
            virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form *a);
