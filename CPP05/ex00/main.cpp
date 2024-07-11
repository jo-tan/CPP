/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:16:43 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/11 18:19:05 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try {
        Bureaucrat bureaucrat("test", 1);

        bureaucrat.Decrement();
        bureaucrat.Increment();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl; 
    
    
    try {
        Bureaucrat a(42);
        Bureaucrat b(21, "Bob");
        Bureaucrat c("Amy");
        

        a.Decrement();
        b.Decrement();
        c.Decrement();
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;

    try {
        Bureaucrat *a = new Bureaucrat(-22);

        std::cout << a << std::endl;
        
        delete a;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}