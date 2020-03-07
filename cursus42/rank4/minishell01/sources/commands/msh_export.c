/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:10:31 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/20 12:54:54 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_export(char **args, t_var *var)
{
	int		j;
	int		i;
	char	*tmp;

	j = 1;
	if (!args[j])
		msh_env(args, var);
	while (args[j])
	{
		if (!(i = check_variable(args[j])))
		{
			var->ret = 1;
			return ;
		}
		tmp = NULL;
		if ((tmp = ft_strchr(args[j], '=')))
			*tmp = 0;
		if (!(tmp++))
			set_var(args[j], get_var_value(i, args[j], var->local), var->envp);
		else
			set_var(args[j], tmp, var->envp);
		erase_var(args[j++], var->local);
	}
	var->ret = 0;
}
