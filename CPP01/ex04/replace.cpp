/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 06:30:51 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/17 07:12:31 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ft_replace(std::ifstream &file, std::string const &name, std::string const &from, std::string const &to)
{
	std::ofstream	newfile;
	std::string		filename;
	std::string		text;
	std::size_t		pos;
	std::size_t		i = 0;

	filename = name + ".replace";
	newfile.open(filename.c_str(), std::ofstream::trunc);
    if (!newfile)
    {
        std::cerr << "Error: Unable to create the output file" << std::endl;
        file.close();
        newfile.close();
        return ;
    }
	std::getline(file, text, '\0');
	pos = text.find(from);
	for (;pos != std::string::npos; pos = text.find(from, i))
	{
		for (; i < pos; ++i)
			newfile << text[i];
		newfile << to;
		i += from.size();
	}
	for (; i < text.size(); ++i)
		newfile << text[i];
}
