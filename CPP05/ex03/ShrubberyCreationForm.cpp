/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:09 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:36:18 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) 
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm( src ), _target( src._target ) 
{}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm &cpy ) 
{
    (void)cpy;
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
    return _target;
}

void    ShrubberyCreationForm::execute( const Bureaucrat &executor ) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file( this->getTarget().append("_shrubbery").c_str() );
    file << ASCII_TREE << std::endl;
    file.close();
}