# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:44:50 by acarvaja          #+#    #+#              #
#    Updated: 2020/01/27 21:57:35 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ./get_next_line/get_next_line.c
MAIN		= main.c
HEADS		= ./minishell.h
OBJS		= ${SRCS:.c=.o}
NAME		= minishell.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OUT			= minishell
PRINTF		= ft_printf/

all:		${NAME}

$(NAME):	${OBJS}
			@make -C $(PRINTF)
			cp ft_printf/libftprintf.a ./$(NAME)
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

out:		${HEADS}
			${CC} ${CFLAGS} $(MAIN) ${SRCS} $(NAME) -o ${OUT} && ./${OUT}