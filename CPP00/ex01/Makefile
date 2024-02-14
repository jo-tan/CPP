# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 10:02:04 by jo-tan            #+#    #+#              #
#    Updated: 2024/02/14 10:11:39 by jo-tan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRC = 	phonebook.cpp \
		contact.cpp \
		main.cpp

O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(O_DIR)/, $(SRC:.cpp=.d))

CC = c++
CF = -Wall -Wextra -Werror -g3 -std=c++98 -MMD

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CF) $^ -o $@
	@echo " [ ok ] | execution file ready!"

-include $(DEP)

$(O_DIR)/%.o: %.cpp | $(O_DIR)
	$(CC) $(CF) -c $< -o $@

$(O_DIR):
	mkdir -p $@

clean:
			@rm -rf $(O_DIR)
			@echo "Remove object and dependent files."

fclean:		clean
			@rm -rf $(NAME)
			@echo "Remove execution file."

re:			fclean all

.PHONY:		all clean fclean re
