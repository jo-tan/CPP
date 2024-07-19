/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:15:04 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:19:50 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
private:
    std::string _target;
    PresidentialPardonAForm();

public:
    PresidentialPardonAForm(const std::string& target);
    PresidentialPardonAForm(const PresidentialPardonAForm &obj);
    ~PresidentialPardonAForm();
    PresidentialPardonAForm &operator=(const PresidentialPardonAForm &obj);
    
    void execute( const Bureaucrat& executor ) const;
};
