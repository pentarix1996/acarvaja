/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:38:47 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/24 17:35:25 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/includes/minishell.h"

int		main(int argc, char **argv, char **envp)
{
	int		i;
	t_var	var;

	var.envp = envp;
	var.local = (char **)malloc(sizeof(char *) * 31);
	var.local[0] = NULL;
	var.ret = 0;
	i = 0;
	(void)argv;
	if (argc == 1)
	{
		while (var.envp[i])
		{
			var.envp[i] = ft_strdup(var.envp[i]);
			i++;
		}
		check_stty(envp);
		msh_loop(&var);
	}
	return (0);
}
