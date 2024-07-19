/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:16:43 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/18 23:39:34 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << MAGENTA << "<< Default Test >>" << RESET << std::endl;
	try {
        Bureaucrat bureaucrat(1);

        bureaucrat.Decrement();
        bureaucrat.Increment();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl; 
    
    std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << MAGENTA << "<< Basic Function Test (with 1 exception)>>" << RESET << std::endl;
    try {
        Bureaucrat a(42);
        Bureaucrat b(21, "Bob");
        Bureaucrat c("Amy");
        
        a.Decrement();
        a.Increment();
        b.Decrement();
        b.Increment();
        c.Decrement();
        c.Increment();
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << MAGENTA << "<< Exception Test >>" << RESET << std::endl;
    
    // grade too high
    try {
        Bureaucrat *a = new Bureaucrat(-22);

        std::cout << a << std::endl;
        
        delete a;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    // grade too low
    try {
        Bureaucrat *a = new Bureaucrat(200);

        std::cout << a << std::endl;
        
        delete a;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << MAGENTA << "END OF TEST" << RESET << std::endl;
    return 0;
}