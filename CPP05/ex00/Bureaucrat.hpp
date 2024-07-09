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
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const	std::string _name;

	public:
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &obj);
		
		std::string	getName();
		int		getGrade();
		GradeTooHighException;
		GradeTooLowException;
		UpGrade; //e.g. lv.3 to lv.2
		DownGrade;//if grade is out of range, return the same exceptions as the constructor
};
