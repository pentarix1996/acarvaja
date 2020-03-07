/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:20:12 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/19 16:11:30 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_var(char *variable, char **array)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (variable[len] != '=' && variable[len])
		len++;
	while (array[i] != NULL &&
		(ft_strncmp(variable, array[i], len) || array[i][len] != 61))
		i++;
	return (i);
}

char	*get_var_value(int var_len, char *variable, char **array)
{
	int		i;
	char	*value;
	char	*tmp;

	i = 0;
	while (array[i] != NULL &&
		(ft_strncmp(variable, array[i], var_len) || array[i][var_len] != 61))
		i++;
	if (array[i] != NULL)
	{
		tmp = ft_strchr(array[i], '=');
		value = ++tmp;
	}
	else
		value = NULL;
	return (value);
}

void	set_new_var(int i, char *variable, char *value, char **array)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strjoin(variable, "=");
	if (value)
	{
		tmp = ft_strjoin(tmp2, value);
		free(tmp2);
		array[i] = strdup(tmp);
		free(tmp);
	}
	else
	{
		array[i] = strdup(tmp2);
		free(tmp2);
	}
	array[i + 1] = NULL;
}

void	set_var(char *variable, char *value, char **array)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = get_var(variable, array);
	if (array[i])
	{
		tmp = ft_strchr(array[i], '=');
		++tmp;
		*tmp = 0;
		tmp2 = ft_strjoin(array[i], value);
		free(array[i]);
		array[i] = tmp2;
	}
	else
		set_new_var(i, variable, value, array);
}

void	erase_var(char *variable, char **array)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
		i++;
	j = get_var(variable, array);
	array[j] = array[i - 1];
	array[i - 1] = NULL;
}
