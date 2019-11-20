/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:45:34 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 11:41:30 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

void	ft_putstr(char *str)
{
	while (str[0] != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	imp_error(char *filestr)
{
	if (errno == 21)
	{
		ft_putstr("cat: ");
		ft_putstr(filestr);
		ft_putstr(": Is a directory");
	}
	else
	{
		ft_putstr("cat: ");
		ft_putstr(filestr);
		ft_putstr(": No such file or directory");
	}
	ft_putstr("\n");
}

void	read_file(char *filestr)
{
	char	c;
	int		file_id;

	file_id = 0;
	file_id = open(filestr, O_RDWR);
	if (file_id < 0)
		imp_error(filestr);
	else
	{
		while (read(file_id, &c, 1))
			write(1, &c, 1);
		close(file_id);
	}
}

void	standart_input(void)
{
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0)
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		standart_input();
	else
		while (i < argc)
			read_file(argv[i++]);
	return (0);
}
