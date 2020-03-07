/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:03:34 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/19 09:12:27 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char **gnl, char **line, int bt)
{
	char	*nl;
	char	*aux;

	if (!bt && !*gnl)
		*line = ft_strdup("");
	if ((nl = ft_strchr(*gnl, '\n')))
	{
		*nl = 0;
		*line = ft_strdup(*gnl);
		aux = ft_strdup(++nl);
		free(*gnl);
		*gnl = aux;
		return (1);
	}
	else
	{
		*line = *gnl;
		free(*gnl);
		*gnl = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int				bt;
	char			buff[BUFFER_SIZE + 1];
	static char		*gnl;
	char			*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((ft_strchr(gnl, '\n')) == NULL)
	{
		bt = read(0, buff, BUFFER_SIZE);
		if (bt < 0)
			return (-1);
		else if (!bt)
			break ;
		buff[bt] = 0;
		if (!gnl)
			gnl = ft_strdup(buff);
		else if (gnl)
		{
			aux = ft_strjoin(gnl, buff);
			free(gnl);
			gnl = aux;
		}
	}
	return (check(&gnl, line, bt));
}
