# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:25:40 by avaldes-          #+#    #+#              #
#    Updated: 2019/09/24 14:28:37 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= rush-02
CFLAGS		= -Wextra -Wall -Werror
MAIN		= src/main.c
LIBS		= src/libs/dict.c src/libs/error.c src/libs/number.c src/libs/string.c #src/libs/number.h
OBJS		= ${MAIN:.c=.o} ${LIBS:.c=.o}
CC			= cc
RM			= rm -f
EXEC		= -o ${NAME}

${NAME}:	${OBJS}
			 		${CC} ${CFLAGS} ${OBJS} ${EXEC}

all:			${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
