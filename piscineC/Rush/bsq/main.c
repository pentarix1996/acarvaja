/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:43:16 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/25 11:02:18 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_stdin_reader(char *read, char c, int size)
{
	char	*temp;
	char	aux[2];

	temp = malloc(sizeof(char) * (size + 2));
	ft_strcpy(temp, read);
	aux[0] = c;
	aux[1] = '\0';
	ft_strcat(temp, aux);
	free(read);
	return (temp);
}

void	free_memory(t_map my_map)
{
	int i;

	i = 0;
	while (i < my_map.ysize)
	{
		free(my_map.content[i]);
		i++;
	}
}

void	perl_input(t_map *map, int argc)
{
	char	c;
	char	*strmap;
	int		i;
	int		map_check;

	i = 0;
	map_check = 0;
	strmap = malloc(2);
	strmap[0] = '\0';
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		strmap = ft_stdin_reader(strmap, c, i);
		i++;
	}
	strmap[i] = '\0';
	map_check = ft_map_check(strmap);
	if (!ft_map_reader(strmap, map) && map_check > 0)
		ft_putstr("Perl error: Map generated error");
	else
		print_result(*map, i, argc);
	free_memory(*map);
}

void	read_next_map(char *argv, t_map *map, int i, int argc)
{
	int		file_size;
	char	*strmap;
	int		map_check;

	file_size = ft_file_size(argv);
	strmap = ft_file_read(argv, file_size);
	map_check = ft_map_check(strmap);
	if (map_check > 0)
	{
		ft_putstr(argv);
		ft_putstr("\n");
		ft_putstr("map error\n\n");
	}
	else
	{
		ft_putstr(argv);
		ft_putchar('\n');
		ft_map_reader(strmap, map);
		print_result(*map, i, argc);
		free_memory(*map);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_map	map;

	i = 0;
	if (argc == 1)
		perl_input(&map, argc);
	else
	{
		i = 1;
		while (i < argc)
		{
			read_next_map(argv[i], &map, i, argc);
			i++;
		}
	}
	return (0);
}
