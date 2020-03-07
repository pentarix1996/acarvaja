/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:38:03 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/21 11:36:02 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		loop_redir(t_command c, t_var *var, int ispipe, int j)
{
	int fd;
	int i;

	i = -1;
	while (c.redir[j][++i])
	{
		if (c.redir[j][i + 1] && (!ft_strcmp(c.redir[j][i], "<")
			|| !ft_strcmp(c.redir[j][i], "<<")))
		{
			fd = open(c.redir[j][++i], O_RDONLY, 0640);
			dup2(fd, STDIN_FILENO);
		}
		else if (c.redir[j][i + 1] && ft_strchr(c.redir[j][i], '>'))
		{
			if (!ft_strcmp(c.redir[j][i], ">>"))
				fd = open(c.redir[j][++i], O_WRONLY | O_CREAT | O_APPEND, 0640);
			else
				fd = open(c.redir[j][++i], O_WRONLY | O_CREAT | O_TRUNC, 0640);
			do_redirect(fd, c.args[j], var, ispipe);
		}
		close(fd);
		if (!c.redir[j][i + 1])
			msh_execute(c.args[j], var);
	}
}

void		redir(t_command commands, t_var *var, int j, int ispipe)
{
	int		out[2];

	if (commands.redir && commands.redir[j])
	{
		if (!ispipe)
		{
			out[1] = dup(STDOUT_FILENO);
			out[0] = dup(STDIN_FILENO);
		}
		loop_redir(commands, var, ispipe, j);
		if (!ispipe)
		{
			dup2(out[1], STDOUT_FILENO);
			dup2(out[0], STDIN_FILENO);
		}
	}
	else
		msh_execute(commands.args[j], var);
}

void		close_and_wait(int j, int *pipefd, t_command commands, pid_t *pid)
{
	j = 0;
	while (j < 2 * commands.count - 1)
		close(pipefd[j++]);
	j = 0;
	while (j < commands.count)
		waitpid(pid[j++], 0, WUNTRACED);
}

void		do_redirect_pipe(int i, int *pipefd, t_command commands)
{
	if (i != 0)
		if (dup2(pipefd[(i - 1) * 2], STDIN_FILENO) < 0)
			permission_denied(commands.args[i][0]);
	if (i != commands.count - 1)
		if (dup2(pipefd[(i * 2 + 1)], STDOUT_FILENO) < 0)
			permission_denied(commands.args[i][0]);
}

void		msh_execute_pipe(t_command commands, t_var *var)
{
	int		pipefd[2 * (commands.count - 1)];
	int		i;
	int		j;
	pid_t	pid[commands.count];

	j = 0;
	while (j < commands.count - 1)
		pipe(pipefd + 2 * j++);
	i = -1;
	while (++i < commands.count)
	{
		if ((pid[i] = fork()) == -1)
			ft_printf("\nFallo en fork");
		else if (pid[i] == 0)
		{
			do_redirect_pipe(i, pipefd, commands);
			j = 0;
			while (j < 2 * commands.count - 1)
				close(pipefd[j++]);
			i == commands.count - 1 ? redir(commands, var, i, 0)
								: redir(commands, var, i, 1);
			exit(0);
		}
	}
	close_and_wait(j, pipefd, commands, pid);
}
