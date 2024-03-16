/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:25:19 by jo-tan            #+#    #+#             */
/*   Updated: 2024/03/16 08:41:35 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;241m"

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();

    Brain &operator=(const Brain &obj);

    void newIdea(size_t num, std::string idea);
    std::string getIdea(size_t i) const;
    const std::string* getIdeaAddress(size_t i) const;
};
