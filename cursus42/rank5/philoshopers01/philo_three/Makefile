# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:44:50 by acarvaja          #+#    #+#              #
#    Updated: 2020/03/07 01:38:02 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= utils.c philo_info.c multi_info.c util_info.c fork.c actions.c
SRCSPATH	= sources/
HEADS		= /includes/philoshopers.h
OBJSPATH	= objects/
OBJS		= $(addprefix $(OBJSPATH), $(SRCS:.c=.o))
OBJS		+= $(addprefix $(OBJSPATH), $(MAIN:.c=.o))
NAME		= philo_three
MAIN		= main.c
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

$(OBJSPATH)%.o: 	$(SRCSPATH)%.c | $(OBJSPATH)
			@$(CC) $(CFLAGS) -c -o $@ $<
$(OBJSPATH)%.o: 	./%.c | $(OBJSPATH)
			@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	${OBJS}
			@echo "Compilando..."
			@${CC} ${CFLAGS} $(OBJS) -o $@

$(OBJSPATH):
			mkdir objects

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

out:		re
			./$(NAME) 4 750 100 75 2
