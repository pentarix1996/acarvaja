/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:18:11 by acarvaja          #+#    #+#             */
/*   Updated: 2019/12/23 18:36:58 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_imput_error(int argc)
{
	if (argc == -4)
		ft_putstr("Error: Parametros incorrectos\nPruebe: --save\n");
	else if (argc < 2)
		ft_putstr("Error: Faltan argumentos (Mapa)\n");
	else if (argc > 3)
		ft_putstr("Error: Sobran argumentos\n");
	else
		ft_putstr("Error: Mapa incorrecto\n");
}

void	put_map_error2(int err)
{
	if (err == -8)
		ft_putstr("Parametro de Floor incorrecto\
			\nPruebe: F (RRR),(GGG),(BBB)\n");
	else if (err == -9)
		ft_putstr("Parametro de Sky incorrecto\
			\nPruebe: C (RRR),(GGG),(BBB)\n");
}

void	put_map_error(int err)
{
	if (err == -1)
		ft_putstr("Parametro de la resolucion incorrecto\
			\nPruebe: R (Width) (Height)\n");
	else if (err == -2)
		ft_putstr("Parametro de Textura Muro Norte incorrecto\
			\nPruebe: NO ./path_to_the_north_texture\n");
	else if (err == -3)
		ft_putstr("Error en el formato de una de las texturas\
			\nPrueba a poner formato de imagen: xpm");
	else if (err == -4)
		ft_putstr("Parametro de Textura Muro Sur incorrecto\
			\nPruebe: SO ./path_to_the_north_texture\n");
	else if (err == -5)
		ft_putstr("Parametro de Textura Muro Oueste incorrecto\
			\nPruebe: WE ./path_to_the_north_texture\n");
	else if (err == -6)
		ft_putstr("Parametro de Textura Muro Este incorrecto\
			\nPruebe: EA ./path_to_the_north_texture\n");
	else if (err == -7)
		ft_putstr("Parametro de Sprite incorrecto\
			\nPruebe: S ./path_to_the_sprite_texture\n");
	put_map_error2(err);
}

int		main(int argc, char **argv)
{
	int		err;
	t_cb3d	*c3d;

	if (argc >= 2 && argc <= 3)
	{
		if (!(c3d = (t_cb3d *)malloc(sizeof(t_cb3d))))
			ft_putstr("Error al alocar memoria! :`(");
		if ((err = init_cb3d_values(c3d, argv)) > 0)
		{
			do_raycast(c3d);
			cb3d_set_hooks(c3d);
			mlx_loop(c3d->mlx.init);
		}
		else
			put_map_error(err);
	}
	else
		put_imput_error(argc);
	return (0);
}
