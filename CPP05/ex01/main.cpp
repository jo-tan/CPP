/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:11:01 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 05:55:02 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << MAGENTA << "<< Default Test >>" << RESET << std::endl;
		std::cout << GREY << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << GREY << "Check default setting" << RESET << std::endl;
		std::cout << a;
		std::cout << b;

		std::cout << GREY << "Check besigned()" << RESET << std::endl;
		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << GREY << "Deconstructing" << RESET << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << MAGENTA << "<< Basic Function Test >>" << RESET << std::endl;
	{
		std::cout << std::endl;

		std::cout << GREY << "Constructing" << RESET << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("The BIG Boss", 1);
		Form *c = new Form("New Office Contract", 50, 100);
		std::cout << std::endl;

		std::cout << GREY << "Check setting" << RESET << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		std::cout << GREY << a->getName() << " tried to signs the Form" << RESET << std::endl;
		try
		{
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << GREY << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << GREY << std::endl;
		}

		std::cout << GREY << c->getName() << " signs the Form" << RESET << std::endl;
		std::cout << c;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << GREY << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << RESET << std::endl;
		}
		std::cout << c;

		std::cout << GREY << b->getName() << " try to signing the from again" << RESET << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		std::cout << GREY << "Deconstructing" << RESET << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << MAGENTA << "<< Exception Test >>" << RESET << std::endl;
	{
		std::cout << std::endl;

		std::cout << GREY << "Constructing" << RESET << std::endl;
		Form *a = NULL;
		Bureaucrat *b = NULL;

		// grade too low
		try
		{
			b = new Bureaucrat(160);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET << std::endl;
		}
		// grade too high
		try
		{
			b = new Bureaucrat(-22);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET << std::endl;
		}
		// sign-grade too high
		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET  << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << GREY << "Failed: " <<
			e.what() << RESET << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << GREY << "Deconstructing" << RESET << std::endl;
			delete a;
			delete b;
		}
		std::cout << MAGENTA << "END OF TEST" << RESET << std::endl;
	}
	return (0);
}
