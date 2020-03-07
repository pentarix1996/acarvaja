/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:12:08 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/13 19:12:58 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_env(char **args, t_var *var)
{
	int		i;

	if (args[1])
	{
		ft_printf("\e[1;31;1menv: too many arguments\e[00;m\n");
		return ;
	}
	else
	{
		i = 0;
		while (var->envp[i])
		{
			ft_printf("%s\n", var->envp[i]);
			i++;
		}
	}
	var->ret = 0;
}
