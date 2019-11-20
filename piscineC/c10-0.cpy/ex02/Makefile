# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 14:05:39 by acarvaja          #+#    #+#              #
#    Updated: 2019/09/25 11:59:37 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_tail

CFLAGS		= -Wall -Werror -Wextra

SRC			= main.c

OBJS		= ${SRC:.c=.o}

CC 			= gcc

RM			= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) -o ${NAME} $(CFLAGS) $(OBJS)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
