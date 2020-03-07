/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:12:37 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/19 13:14:56 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**split_path(char *path)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = ft_split(path, '/');
	while (tmp[i])
	{
		j = 0;
		if (!ft_strcmp(tmp[i], ".."))
		{
			while (!(ft_strcmp(tmp[i - j], "..")))
				j++;
			free(tmp[i - j]);
			tmp[i - j] = ft_strdup("..");
		}
		i++;
	}
	return (tmp);
}

char	*msh_parse_path(char *path)
{
	char	**tmp;
	char	*tmp2;
	int		i;

	i = 0;
	if (ft_strchr(path, '.'))
	{
		tmp = split_path(path);
		free(path);
		path = ft_strdup("");
		while (tmp[i])
		{
			if (!ft_strcmp(tmp[i], "..") || !ft_strcmp(tmp[i], "."))
				i++;
			else
			{
				tmp2 = ft_strjoin(path, "/");
				free(path);
				path = ft_strjoin(tmp2, tmp[i++]);
				free(tmp2);
			}
		}
		free_double_array(tmp);
	}
	return (path);
}
