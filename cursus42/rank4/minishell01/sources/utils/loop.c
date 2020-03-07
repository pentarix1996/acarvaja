/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:18:55 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/24 14:05:57 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *g_builtin_str[7] =
{
	"cd",
	"echo",
	"pwd",
	"exit",
	"env",
	"export",
	"unset"
};

void (*g_builtin_func[7]) (char **, t_var *) =
{
	&msh_cd,
	&msh_echo,
	&msh_pwd,
	&msh_exit,
	&msh_env,
	&msh_export,
	&msh_unset
};

void	msh_loop(t_var *var)
{
	t_command	*commands;
	char		*line;
	int			count;
	int			i;

	put_title();
	while (1)
	{
		display_prompt();
		signal(SIGQUIT, signal_quit_hundler);
		signal(SIGINT, signal_interrupt_handler);
		msh_read_line(&line);
		commands = fill_commands(line, &count, var);
		free(line);
		line = NULL;
		i = -1;
		while (++i < count)
			!commands[i].fpipe ? redir(commands[i], var, 0, 0) :
								msh_execute_pipe(commands[i], var);
		free_args(commands, count);
		free_redir(commands, count);
		free(commands);
	}
	free_double_array(var->envp);
	free_double_array(var->local);
}

void	check_stty(char **envp)
{
	pid_t	pid;
	char	*cmd;
	char	*cmd_args[3];

	if (!(pid = fork()))
	{
		cmd = ft_strdup("/bin/stty");
		cmd_args[0] = ft_strdup("stty");
		cmd_args[1] = ft_strdup("-ctlecho");
		cmd_args[2] = 0;
		execve(cmd, cmd_args, envp);
		free(cmd);
		free(cmd_args[0]);
		free(cmd_args[1]);
	}
}
