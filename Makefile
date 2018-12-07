# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 14:31:00 by trabut            #+#    #+#              #
#    Updated: 2018/12/07 15:27:36 by lbonnete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

SRC =

OBJ =

LIB =

INC =

all: $(NAME)

$(NAME):
	@echo "\nBuilding Project...\n"
	@gcc -c -Wall -Wextra -Werror $(SRC) $(LIB)
	@echo "Compilation Successful"
	@echo "Project Ready"

p: all clean

clean:
	@/bin/rm -f $(OBJ)
	@echo "Objects Destroyed"

fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "Project Destroyed"

re:	fclean all

norm:
	@norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm