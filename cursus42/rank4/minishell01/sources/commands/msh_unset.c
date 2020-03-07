/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:12:36 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/13 19:12:37 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_unset(char **args, t_var *var)
{
	int		i;

	i = 0;
	while (args[i])
	{
		erase_var(args[i], var->envp);
		erase_var(args[i], var->local);
		i++;
	}
	var->ret = 0;
}
