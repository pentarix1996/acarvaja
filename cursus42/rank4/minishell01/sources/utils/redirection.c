/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:57:18 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 16:27:40 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		fill_redir(int k, char *line, t_command *commands, t_var *var)
{
	int		l;
	int		j;
	char	*tmp;
	char	**tmp2;

	commands->redir = (char ***)malloc(sizeof(char **));
	commands->redir[0] = (char **)malloc(sizeof(char *) * (k * 2 + 1));
	k = parse_commands(line, '>', '<');
	l = 0;
	while (line[k])
	{
		if (!(j = parse_commands(line + k + 1, '>', '<')))
			commands->redir[0][l++] = ft_substr(line, k++, 2);
		else
			commands->redir[0][l++] = ft_substr(line, k, 1);
		j = parse_commands(line + ++k, '>', '<');
		tmp = ft_substr(line, k, j);
		tmp2 = msh_parse_line(&tmp, var);
		commands->redir[0][l++] = ft_strdup(*tmp2);
		free_double_array(tmp2);
		free(tmp);
		k += j;
	}
	line[parse_commands(line, '>', '<')] = 0;
	commands->redir[0][l] = NULL;
}

t_command	parse_redir(char *line, t_var *var)
{
	int			k;
	t_command	commands;

	commands.redir = NULL;
	commands.fpipe = 0;
	if ((k = count_commands(line, '>', '<')))
		fill_redir(k, line, &commands, var);
	commands.args = malloc(sizeof(char **));
	commands.args[0] = msh_parse_line(&line, var);
	commands.count = 1;
	return (commands);
}

void		free_temps(char *tmp, char **tmp2)
{
	free_double_array(tmp2);
	free(tmp);
}

char		**fill_pipe_redir(int k, char *new_line, t_var *var)
{
	int		j;
	int		l;
	char	*tmp;
	char	**tmp2;
	char	**redir;

	redir = (char **)malloc(sizeof(char *) * (k * 2 + 1));
	k = parse_commands(new_line, '>', '<');
	l = 0;
	while (new_line[k])
	{
		if (!(j = parse_commands(new_line + k + 1, '>', '<')))
			redir[l++] = ft_substr(new_line, k++, 2);
		else
			redir[l++] = ft_substr(new_line, k, 1);
		j = parse_commands(new_line + ++k, '>', '<');
		tmp = ft_substr(new_line, k, j);
		tmp2 = msh_parse_line(&tmp, var);
		redir[l++] = ft_strdup(*tmp2);
		free_temps(tmp, tmp2);
		k += j;
	}
	new_line[parse_commands(new_line, '>', '<')] = 0;
	redir[l] = NULL;
	return (redir);
}

void		parse_pipe_redir(t_command *cmd, int i, char **line, t_var *var)
{
	char	*new_line;
	int		h;
	int		k;

	h = parse_commands(*line, '|', 0);
	new_line = ft_substr(*line, 0, h);
	if (cmd->redir)
		cmd->redir[i] = NULL;
	if ((k = count_commands(new_line, '>', '<')))
		cmd->redir[i] = fill_pipe_redir(k, new_line, var);
	cmd->args[i] = msh_parse_line(&new_line, var);
	*line += h;
	if (*line)
		(*line)++;
	free(new_line);
}
