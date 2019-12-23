# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:44:50 by acarvaja          #+#    #+#              #
#    Updated: 2019/12/23 19:15:49 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSLIB		= $(LIBFT)ft_isalnum.c $(LIBFT)ft_isalpha.c $(LIBFT)ft_isascii.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_isprint.c \
              $(LIBFT)ft_memccpy.c $(LIBFT)ft_memchr.c $(LIBFT)ft_memcmp.c $(LIBFT)ft_memcpy.c $(LIBFT)ft_memmove.c \
              $(LIBFT)ft_memset.c  $(LIBFT)ft_strchr.c $(LIBFT)ft_strlcat.c $(LIBFT)ft_strlcpy.c $(LIBFT)ft_strlen.c \
              $(LIBFT)ft_strncmp.c $(LIBFT)ft_strnstr.c $(LIBFT)ft_strrchr.c $(LIBFT)ft_tolower.c $(LIBFT)ft_toupper.c \
              $(LIBFT)ft_atoi.c $(LIBFT)ft_bzero.c $(LIBFT)ft_calloc.c $(LIBFT)ft_strdup.c $(LIBFT)ft_substr.c $(LIBFT)ft_strjoin.c \
			  $(LIBFT)ft_strtrim.c $(LIBFT)ft_split.c $(LIBFT)ft_itoa.c $(LIBFT)ft_strmapi.c $(LIBFT)ft_putchar_fd.c \
			  $(LIBFT)ft_putstr_fd.c $(LIBFT)ft_putendl_fd.c $(LIBFT)ft_putnbr_fd.c
SRCS		= set_hooks.c movement1.c movement2.c init_values.c put_values1.c put_textures1.c put_textures2.c put_values2.c \
			  raycaster1.c raycaster2.c raycaster3.c
MAIN		= main.c
HEADS		= ./ft_printf.h
OBJS		= $(SRCS:.c=.o)
DIR_S 		= sources
DIR_O 		= temporary
HEADER 		= include
LIBFT 		= libft/
GETNEXTL	= get_next_line/
NAME		= libcub3d.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LMLXCOMP	= -lmlx -framework OpenGL -framework AppKit
OUT			= cub3d.out

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)

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

out:
	${CC} $(CFLAGS) $(SRCS) $(MAIN) $(GETNEXTL)get_next_line.c  $(GETNEXTL)get_next_line_utils.c \
		./minilibx_opengl/libmlx.a $(LIBFT)libft.a $(LMLXCOMP) -o ${OUT} && ./${OUT} ./maps/test1.cub

out_no_map:
	${CC} $(CFLAGS) $(SRCS) $(MAIN) $(GETNEXTL)get_next_line.c  $(GETNEXTL)get_next_line_utils.c \
		./minilibx_opengl/libmlx.a $(LIBFT)libft.a $(LMLXCOMP) -o ${OUT}

bonus: all
