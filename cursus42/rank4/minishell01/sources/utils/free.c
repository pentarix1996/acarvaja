/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:12:49 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 16:24:01 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_args(t_command *commands, int count)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < commands[i].count)
		{
			z = 0;
			while (commands[i].args[j][z])
				free(commands[i].args[j][z++]);
			free(commands[i].args[j]);
			j++;
		}
		free(commands[i].args);
		i++;
	}
}

void	free_redir(t_command *commands, int count)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	while (i < count)
	{
		if (commands[i].redir)
		{
			j = 0;
			while (j < commands[i].count)
			{
				z = 0;
				if (commands[i].redir[j])
				{
					while (commands[i].redir[j][z])
						free(commands[i].redir[j][z++]);
					free(commands[i].redir[j]);
				}
				j++;
			}
			free(commands[i].redir);
		}
		i++;
	}
}

void	free_double_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
