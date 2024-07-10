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
