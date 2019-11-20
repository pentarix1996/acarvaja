/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:01:59 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 11:39:44 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (str[0] != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	imp_error(int error)
{
	if (error == -1)
		ft_putstr("File name missing.");
	else if (error == -2)
		ft_putstr("Too many arguments.");
	else if (error == -3)
		ft_putstr("Cannot read file.");
	ft_putstr("\n");
}

void	read_file(char *filestr)
{
	char	c;
	int		file_id;

	file_id = 0;
	file_id = open(filestr, O_RDONLY);
	if (file_id < 0)
		imp_error(-3);
	else
	{
		while (read(file_id, &c, 1))
			write(1, &c, 1);
		close(file_id);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		imp_error(-1);
	else if (argc > 2)
		imp_error(-2);
	else
		read_file(argv[1]);
	return (0);
}
