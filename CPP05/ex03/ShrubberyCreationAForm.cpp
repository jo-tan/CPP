/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationAForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:09 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:20:48 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationAForm.hpp"

ShrubberyCreationAForm::ShrubberyCreationAForm( const std::string &target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) 
{}

ShrubberyCreationAForm::ShrubberyCreationAForm( const ShrubberyCreationAForm &src ) : AForm( src ), _target( src._target ) 
{}

ShrubberyCreationAForm::~ShrubberyCreationAForm() 
{}

ShrubberyCreationAForm &ShrubberyCreationAForm::operator=( ShrubberyCreationAForm &cpy ) 
{
    (void)cpy;
    return *this;
}

std::string ShrubberyCreationAForm::getTarget() const{
    return _target;
}

void    ShrubberyCreationAForm::execute( const Bureaucrat &executor ) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file( this->getTarget().append("_shrubbery").c_str() );
    file << ASCII_TREE << std::endl;
    file.close();
}