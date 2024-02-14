/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:01:47 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/14 10:01:49 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>

class Contact
{
    public:
        Contact();
        ~Contact();
    
        void    setFirstName(std::string str);
        void    setLastName(std::string str);
        void    setPhoneNumber(std::string str);
        void    setMemo(std::string str);

        std::string     getFirstName(void);
        std::string     getLastName(void);
        std::string     getPhoneNumber(void);
        std::string     getMemo(void);
    private:
        std::string     _firstname;
        std::string     _lastname;
        std::string     _phonenumber;
        std::string     _memo;
};

#endif
