/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:45:38 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 16:17:57 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_var_swap(char *str, char **ptr, t_var *var)
{
	int		len;
	char	*tmp;
	int		i;

	len = 0;
	i = 0;
	if (str[++i] == '?')
	{
		tmp = ft_itoa(var->ret);
		len = ft_strlen(tmp);
	}
	else
	{
		len = parse_var_len(&(str[i]));
		if (!(tmp = ft_strdup(get_var_value(len, &(str[i]), var->envp))))
			tmp = ft_strdup(get_var_value(len, &(str[i]), var->local));
	}
	if (tmp)
	{
		ft_strcpy(*ptr, tmp);
		(*ptr) += ft_strlen(tmp);
		free(tmp);
	}
	i += len;
	return (i);
}

int		ft_strchr_count(const char *str, int asc)
{
	int i;

	i = 0;
	while (str[i] >= 0)
	{
		if (str[i] == asc)
			return (i);
		if (!str[i] && str[i] == asc)
			return (i);
		if (!str[i])
			break ;
		i++;
	}
	return (ft_strlen(str));
}

int		check_variable(char *variable)
{
	int		i;
	int		flag_char;

	i = 0;
	flag_char = 0;
	while (variable[i] != '=' && variable[i])
	{
		if (!(flag_char = ft_isalpha(variable[i])) && !ft_isdigit(variable[i]))
		{
			ft_printf("\e[1;31;1mMinishell: export: '%s'", variable);
			ft_printf(": not valid identifier\n");
			return (0);
		}
		i++;
	}
	if (!i || !flag_char)
	{
		ft_printf("\e[1;31;1mMinishell: export: '%s'", variable);
		ft_printf(": not valid identifier\n");
		return (0);
	}
	return (i);
}

int		msh_bar_count(char *str, int *i)
{
	int		bar;

	bar = 0;
	while (str[*i] == '\\')
	{
		bar++;
		(*i)++;
	}
	return (bar);
}

int		parse_var_len(char *variable)
{
	int		i;

	i = 0;
	while (variable[i] && ft_isalnum(variable[i]))
		i++;
	return (i);
}
