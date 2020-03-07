/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:11:02 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/13 19:11:10 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_pwd(char **args, t_var *var)
{
	char	*buf;

	(void)args;
	buf = get_var_value(3, "PWD", var->envp);
	ft_printf("%s\n", buf);
	var->ret = 0;
}
