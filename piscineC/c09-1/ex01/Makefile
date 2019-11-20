# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 23:38:22 by acarvaja          #+#    #+#              #
#    Updated: 2019/09/26 18:51:14 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
HEADS		= ./includes/ft.h
OBJS		= ${SRCS:.c=.o}       
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:		${HEADS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
