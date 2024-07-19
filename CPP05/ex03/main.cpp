/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:15:15 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:58:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationAForm.hpp"
#include "RobotomyRequestAForm.hpp"
#include "PresidentialPardonAForm.hpp"
#include "Intern.hpp"

int main( void )
{
    std::cout << MAGENTA << "<< Basic Test >>" << RESET << std::endl;
	std::cout << GREY << "Constructing" << RESET << std::endl;
    Intern  someRandomIntern;
    
    AForm   *rr = NULL;
    rr = someRandomIntern.makeForm("", "Bender");
    delete rr;
    
    AForm   *rrf = NULL;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;

    AForm   *rrff = NULL;
    rrff = someRandomIntern.makeForm("shrubbery", "Bender");
    delete rrff;

    AForm   *rrfff = NULL;
    rrfff = someRandomIntern.makeForm("shrubbery creation", "Bender");
    delete rrfff;
    
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << MAGENTA << "<< Exception Test: without a target >>" << RESET << std::endl;
    try{
        AForm   *rrffff = NULL;
        rrffff = someRandomIntern.makeForm("shrubbery creation", "");
        delete rrffff;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << MAGENTA << "END OF TEST" << RESET << std::endl;
}