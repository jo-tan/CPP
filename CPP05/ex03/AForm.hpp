/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:15:58 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 05:38:19 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
    	const std::string   _name;
    	bool                _signed;
    	const int           _gradeToSign;
    	const int           _gradeToExecute;



	public:
		AForm();
		AForm(const AForm &src);
		AForm(int gradeToSign, int gradeToExecute);
		AForm(const std::string &name);
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		
		virtual ~AForm();

    	AForm &operator=(const AForm &obj);

    	const std::string	getName() const;
    	bool 				getSigned() const;
    	int 				getGradeToSign() const;
    	int 				getGradeToExecute() const;

    	void beSigned(Bureaucrat &signer);
		virtual void execute(const Bureaucrat &executor) const = 0;

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

std::ostream &operator<<(std::ostream &o, AForm *a);