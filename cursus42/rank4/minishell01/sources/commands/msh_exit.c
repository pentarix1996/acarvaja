/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:11:45 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 18:03:54 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_exit(char **args, t_var *var)
{
	int		i;

	i = 0;
	if (args[1] && args[2])
	{
		ft_printf("\e[1;31;1mexit: too many arguments\e[00;m\n");
		var->ret = 1;
		return ;
	}
	else if (args[1])
	{
		while (args[1][i])
		{
			if (!ft_isdigit(args[1][i++]))
			{
				ft_printf("\e[1;31;1mexit: %s:", args[1]);
				ft_printf("numeric argument is required\e[00;m\n");
				var->ret = 255;
				exit(var->ret);
			}
		}
		var->ret = ft_atoi(args[1]);
	}
	system("leaks minishell");
	exit(var->ret);
}
