/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:04:54 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 16:25:15 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			exist_pipe(t_command **commands, char *line, int com_i, t_var *var)
{
	int		i;
	int		len;

	commands[0][com_i].count = 0;
	if ((len = count_commands(line, '|', 0)))
	{
		i = 0;
		commands[0][com_i].redir = NULL;
		commands[0][com_i].count = ++len;
		commands[0][com_i].args = malloc(sizeof(commands[0][com_i].args)
			* (commands[0][com_i].count + 1));
		if (count_commands(line, '>', '<'))
			commands[0][com_i].redir = (char ***)malloc(sizeof(char **)
				* len + 1);
		while (i < len)
			parse_pipe_redir(&commands[0][com_i], i++, &line, var);
		return (1);
	}
	return (0);
}

void		choose_execute(t_command *commands, char *aux, int i, t_var *var)
{
	if (exist_pipe(&commands, aux, i, var))
		commands[i].fpipe = 1;
	else
		commands[i] = parse_redir(aux, var);
}

t_command	*fill_mul_commands(int *count_c, int count, char *line, t_var *var)
{
	t_command	*commands;
	int			len;
	char		*aux;
	int			i;

	i = -1;
	commands = (t_command *)malloc(sizeof(t_command) * (count + 1));
	*count_c = 0;
	while (++i <= count)
	{
		if (count)
		{
			len = parse_commands(line, ';', 0);
			aux = ft_substr(line, 0, len);
			line += len;
			if (line)
				line++;
		}
		else
			aux = ft_strdup(line);
		choose_execute(commands, aux, i, var);
		free(aux);
		*count_c += 1;
	}
	return (commands);
}

t_command	*fill_commands(char *line, int *count_com, t_var *var)
{
	int			count;
	t_command	*commands;

	commands = NULL;
	if ((count = count_commands(line, ';', 0)))
		commands = fill_mul_commands(count_com, count, line, var);
	else
	{
		commands = (t_command *)malloc(sizeof(t_command));
		choose_execute(commands, line, 0, var);
		*count_com = 1;
	}
	return (commands);
}
