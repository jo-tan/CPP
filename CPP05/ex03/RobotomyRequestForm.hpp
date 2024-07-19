/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:41 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 08:35:57 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
private:
    const std::string   _target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &cpy);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm &cpy);

    void    execute(const Bureaucrat &executor) const;
};
