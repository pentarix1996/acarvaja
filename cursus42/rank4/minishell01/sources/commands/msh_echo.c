/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:09:44 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/17 18:35:54 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_echo(char **args, t_var *var)
{
	int		i;
	int		fjump;

	fjump = 0;
	(void)var;
	if (args[1])
	{
		i = 1;
		if (!(ft_strcmp(args[i], "-n")))
			i++;
		else
			fjump = 1;
		while (args[i] != NULL)
		{
			ft_printf("%s", args[i]);
			if (args[i + 1])
				ft_printf(" ");
			i++;
		}
		if (fjump)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	var->ret = 0;
}
