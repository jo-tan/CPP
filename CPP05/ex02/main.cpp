/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:12:24 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:31:07 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    std::cout << MAGENTA << "<< Default Test >>" << RESET << std::endl;
    std::cout << GREY << "Constructing" << RESET << std::endl;
    Bureaucrat bureaucrat("CEO", 2);
    ShrubberyCreationForm form1("Shrubbery");
    RobotomyRequestForm form2("Robotomy");
    PresidentialPardonForm form3("President");

    std::cout << MAGENTA << "\n<< Basic Function Test: Normal >>" << RESET << std::endl;
    try {
        std::cout << "\n---------------Shrubbery---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n---------------Robotomy---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n---------------President--------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << MAGENTA << "<< Exception Test: Unsigned >>" << RESET << std::endl;
    try {
        ShrubberyCreationForm unsignForm1("Unsigned Shurbbery");
        std::cout << "\n---------------Shrubbery---------------" << std::endl;
        bureaucrat.executeForm(unsignForm1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        RobotomyRequestForm unsignForm2("Unsigned Robotomy");
        std::cout << "\n---------------Robotomy---------------" << std::endl;
        bureaucrat.executeForm(unsignForm2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        PresidentialPardonForm unsignForm3("Unsigned President");
        std::cout << "\n---------------President---------------" << std::endl;
        bureaucrat.executeForm(unsignForm3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << MAGENTA << "<< Exception Test: Not allowed to sign or execute >>" << RESET << std::endl;
    Bureaucrat a("Team Head", 64);
    try {
        ShrubberyCreationForm a1("Test3-1");
        std::cout << "\n---------------Shrubbery---------------" << std::endl;
        a.signForm(a1);
        a.executeForm(a1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        RobotomyRequestForm a2("Test3-2");
        std::cout << "\n---------------Robotomy---------------" << std::endl;
        a.signForm(a2);
        a.executeForm(a2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        PresidentialPardonForm a3("Test3-3");
        std::cout << "\n---------------President---------------" << std::endl;
        a.signForm(a3);
        bureaucrat.executeForm(a3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << MAGENTA << "END OF TEST" << RESET << std::endl;
    return 0;
}