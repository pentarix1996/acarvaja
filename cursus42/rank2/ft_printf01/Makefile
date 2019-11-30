# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:44:50 by acarvaja          #+#    #+#              #
#    Updated: 2019/11/30 06:53:24 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSLIB		= $(LIBFT)ft_isalnum.c $(LIBFT)ft_isalpha.c $(LIBFT)ft_isascii.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_isprint.c \
              $(LIBFT)ft_memccpy.c $(LIBFT)ft_memchr.c $(LIBFT)ft_memcmp.c $(LIBFT)ft_memcpy.c $(LIBFT)ft_memmove.c \
              $(LIBFT)ft_memset.c  $(LIBFT)ft_strchr.c $(LIBFT)ft_strlcat.c $(LIBFT)ft_strlcpy.c $(LIBFT)ft_strlen.c \
              $(LIBFT)ft_strncmp.c $(LIBFT)ft_strnstr.c $(LIBFT)ft_strrchr.c $(LIBFT)ft_tolower.c $(LIBFT)ft_toupper.c \
              $(LIBFT)ft_atoi.c $(LIBFT)ft_bzero.c $(LIBFT)ft_calloc.c $(LIBFT)ft_strdup.c $(LIBFT)ft_substr.c $(LIBFT)ft_strjoin.c \
			  $(LIBFT)ft_strtrim.c $(LIBFT)ft_split.c $(LIBFT)ft_itoa.c $(LIBFT)ft_strmapi.c $(LIBFT)ft_putchar_fd.c \
			  $(LIBFT)ft_putstr_fd.c $(LIBFT)ft_putendl_fd.c $(LIBFT)ft_putnbr_fd.c
SRCS		= ft_printf_utils.c ft_printf.c
MAIN		= ft_printf.c
HEADS		= ./ft_printf.h
OBJS		= $(SRCS:.c=.o)
DIR_S 		= sources
DIR_O 		= temporary
HEADER 		= include
LIBFT 		= libft/
NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
OUT			= test.out

t			?= 1234
t1			:= $(t)5678
t			= 9999

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

out:		${HEADS}
			${CC} ${CFLAGS} ${SRCS} ./$(LIBFT)ft_strchr.c ./$(LIBFT)ft_strlen.c ./$(LIBFT)ft_strjoin.c ./$(LIBFT)ft_itoa.c ./$(LIBFT)ft_strlcat.c ./$(LIBFT)ft_strlcpy.c -o ${OUT} && ./${OUT}

test:
	@echo $(t)
	@echo $(t1)
	@echo $(t)