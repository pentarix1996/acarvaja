# **************************************************************************** #$
#                                                                              #$
#                                                         :::      ::::::::    #$
#    Makefile                                           :+:      :+:    :+:    #$
#                                                     +:+ +:+         +:+      #$
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #$
#                                                 +#+#+#+#+#+   +#+            #$
#    Created: 2020/01/16 12:31:47 by acarvaja          #+#    #+#              #$
#    Updated: 2020/01/17 01:31:24 by acarvaja         ###   ########.fr        #$
#                                                                              #$
# **************************************************************************** #$
$
SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s$
MAIN		= main.c$
OBJS		= $(SRC:$(SRC_PATH)/%.s=$(OBJ_PATH)/%.o)$
SRC			= $(addprefix $(SRC_PATH)/,$(SRCS))$
HEADER 		= include$
NAME		= libasm.a$
CC			= nasm$
CFLAGS		= -f macho64$
OUT			= test.out$
INC_PATH	= includes$
SRC_PATH 	= srcs$
$
all: $(NAME)$
$
$(NAME): $(OBJS)$
	@ar rc $(NAME) $(addprefix $(SRC_PATH),$(OBJS))$
	@ranlib $(NAME)$
$
$(OBJS):$
	@$(CC) $(CFLAGS) srcs/ft_strlen.s$
	@$(CC) $(CFLAGS) srcs/ft_strcpy.s$
	@$(CC) $(CFLAGS) srcs/ft_strcmp.s$
	@$(CC) $(CFLAGS) srcs/ft_write.s$
	@$(CC) $(CFLAGS) srcs/ft_read.s$
	@$(CC) $(CFLAGS) srcs/ft_strdup.s$
$
clean:$
	@rm -f $(addprefix $(SRC_PATH),$(OBJS))$
	@rm -rf .obj$
$
fclean: clean$
	@rm -f $(NAME)$
$
re: fclean all$
$
out:$
	gcc -Wall -Werror -Wextra $(MAIN) -L. -lasm -o $(OUT) && ./$(OUT)$
$
bonus: all