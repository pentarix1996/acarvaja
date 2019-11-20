# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 14:05:39 by acarvaja          #+#    #+#              #
#    Updated: 2019/09/24 18:12:54 by atorres-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq

CFLAGS		= -Wall -Werror -Wextra

SRC			= algorithm.c comunes.c file_reader.c main.c map_checker.c map_checker2.c map_reader.c map_solver.c

OBJS		= ${SRC:.c=.o}

CC 			= gcc

RM			= rm -f

$(NAME): 	$(OBJS)
			$(CC) -o ${NAME} $(CFLAGS) $(OBJS)

all: 		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
