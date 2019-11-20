/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:49:00 by atorres-          #+#    #+#             */
/*   Updated: 2019/09/24 17:57:59 by atorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_file_size(char *name)
{
	char	c;
	int		file_id;
	int		i;

	file_id = 0;
	file_id = open(name, O_RDONLY);
	i = 0;
	if (file_id < 0)
		return (file_id);
	while (read(file_id, &c, sizeof(c) != '\0'))
		i++;
	close(file_id);
	return (i);
}

char	*ft_file_read(char *name, int file_size)
{
	char	*buf;
	int		file_id;
	int		bytes_read;

	file_id = 0;
	bytes_read = 0;
	buf = (char *)malloc(file_size);
	file_id = open(name, O_RDONLY);
	if (file_id < 0)
		return (NULL);
	bytes_read = read(file_id, buf, file_size);
	buf[bytes_read] = '\0';
	if (bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	close(file_id);
	return (buf);
}
