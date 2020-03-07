# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:44:50 by acarvaja          #+#    #+#              #
#    Updated: 2020/02/24 13:41:42 by acarvaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTIL		= utils.c utils2.c parse_line.c signal.c parse_path.c read_line.c prompts.c \
				parse_commands.c free.c redirection.c execute.c execute_pipe.c execute_pipe2.c\
				fill_commands.c loop.c
CMDS		= msh_cd.c msh_echo.c msh_export.c msh_env.c msh_exit.c msh_unset.c msh_pwd.c
HEADS		= sources/includes/minishell.h
UTILPATH	= sources/utils/
CMDSPATH	= sources/commands/
OBJSPATH	= objects
SRCSUTIL	=$(addprefix $(UTILPATH), $(UTIL))
SRCSCMD		=$(addprefix $(CMDSPATH), $(CMDS))
OBJS		=$(addprefix $(OBJSPATH)/, $(UTIL:.c=.o))
OBJS		+=$(addprefix $(OBJSPATH)/, $(CMDS:.c=.o))
NAME		= minishell
MAIN		= main.c
LIB			= ft_printf/libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
PRINTF		= ft_printf/
LIBFT		= libft.a

all:		${NAME}

$(OBJSPATH)/%.o: 	$(UTILPATH)%.c | $(OBJSPATH)
			$(CC) $(CFLAGS) -c -o $@ $<
$(OBJSPATH)/%.o: 	$(CMDSPATH)%.c | $(OBJSPATH)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):	${OBJS}
			@make -C $(PRINTF)
			${CC} ${CFLAGS} $(MAIN) $(OBJS) $(LIB) -o $@

$(OBJSPATH):
			mkdir -p objects

clean:
			rm -f ${OBJS}
			@make clean -C $(PRINTF)

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(OBJSPATH)
			@make fclean -C $(PRINTF)
			rm -f $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re

out:		${HEADS} all
			./minishell
