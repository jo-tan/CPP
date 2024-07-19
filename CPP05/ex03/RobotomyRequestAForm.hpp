/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestAForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 05:14:41 by jo-tan            #+#    #+#             */
/*   Updated: 2024/07/19 07:20:23 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestAForm : public AForm
{
private:
    const std::string   _target;
    RobotomyRequestAForm();

public:
    RobotomyRequestAForm(const std::string &target);
    RobotomyRequestAForm(const RobotomyRequestAForm &cpy);
    ~RobotomyRequestAForm();
    RobotomyRequestAForm &operator=(RobotomyRequestAForm &cpy);

    void    execute(const Bureaucrat &executor) const;
};
