# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 23:38:22 by acarvaja          #+#    #+#              #
#    Updated: 2019/09/26 21:37:08 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCDIR		= ./srcs/
SRCS 		= ${SRCDIR}ft_putchar.c ${SRCDIR}ft_swap.c ${SRCDIR}ft_putstr.c ${SRCDIR}ft_strlen.c ${SRCDIR}ft_strcmp.c
HEADERS 	= ./includes/ft.h
FLAGS 		= -Wall -Wextra -Werror
COMPILERC 	= gcc
OBJS		= ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
OBJSDIR		= ${SRCDIR}ft_putchar.o ${SRCDIR}ft_swap.o ${SRCDIR}ft_putstr.o ${SRCDIR}ft_strlen.o ${SRCDIR}ft_strcmp.o
RM			= rm -f

all:	${NAME}

${NAME}:	${OBJSDIR}
			${COMPILERC} ${FLAGS} -c ${SRCS} -I ${HEADERS}
			mv ${OBJS} ${SRCDIR}
			ar rc ${NAME} ${OBJSDIR}
			ranlib ${NAME}

clean:
			${RM} ${OBJSDIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

.PHONY:	all clean fclean re
