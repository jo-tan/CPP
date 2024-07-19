/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonAForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:12:45 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:27:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string& target );
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
    
    void execute(const Bureaucrat &executor) const;
};
