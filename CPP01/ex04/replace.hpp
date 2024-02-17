/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:30:59 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 07:02:43 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REPLACE_HPP__
# define __REPLACE_HPP__

# include <iostream>
# include <fstream>
# include <string>

void	ft_replace(std::ifstream &file, std::string const &name, std::string const &from, std::string const &to);

#endif
