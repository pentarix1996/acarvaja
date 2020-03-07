/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:05:12 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/19 14:05:45 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	do_redirect(int fd, char **args, t_var *var, int ispipe)
{
	if (ispipe)
		msh_execute(args, var);
	dup2(fd, STDOUT_FILENO);
}
