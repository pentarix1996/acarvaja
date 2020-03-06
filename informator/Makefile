SRCS = ./sources/get_next_line/get_next_line.c ./sources/get_next_line/get_next_line_utils.c
MAIN = main.c
HEAD = ./informator.h
OBJS = ${SRCS:.c=.o}
NAME = libinformator.a
CC   = gcc
CFLAGS = -Wall -Wextra -Werror
OUT	= informator

all:	${NAME}
				${CC} ${CFLAGS} $(MAIN) $(NAME) -o ${OUT}

$(NAME):	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

clean:
				rm -f ${OBJS}

fclean:	clean
				rm -f ${NAME}
				rm -f $(OUT)

re:	fclean all

.PHONY:	all clean fclean re bonus

out:	fclean all
			./${OUT}
