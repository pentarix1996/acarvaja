/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:40:44 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/24 18:06:00 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_num_builtins(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}

int		search_path(char **args, t_var *var)
{
	int		ret;
	char	*aux;
	char	*sub_path;
	char	*command;

	if (execve(args[0], args, var->envp) != -1)
		return (1);
	aux = ft_strchr(var->envp[get_var("PATH", var->envp)], '/');
	aux++;
	while (aux)
	{
		ret = ft_strchr_count(aux, ':');
		sub_path = ft_substr(aux, 0, ret);
		aux = ft_strchr(aux, ':');
		command = ft_strjoin(ft_strjoin(sub_path, "/"), args[0]);
		if (execve(command, args, var->envp) != -1)
			return (1);
		if (aux)
			aux++;
	}
	return (0);
}

int		msh_launch(char **args, t_var *var)
{
	pid_t	pid;
	int		status;

	signal(SIGQUIT, proc_signal_quit_hundler);
	signal(SIGINT, proc_signal_handler);
	status = 0;
	if ((pid = fork()) == 0)
	{
		if (!search_path(args, var))
		{
			command_not_found(args[0]);
			return (0);
		}
	}
	else if (pid < 0)
		ft_printf("Minishell → Ocurrio un error");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			var->ret = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			var->ret = 128 + WTERMSIG(status);
	}
	return (1);
}

int		is_builting(char ***args, int *i, t_var *var)
{
	if (ft_strcmp(*args[0], g_builtin_str[*i]) == 0)
	{
		(*g_builtin_func[*i])(*args, var);
		var->ret = 0;
		return (0);
	}
	*i += 1;
	return (1);
}

void	msh_execute(char **args, t_var *var)
{
	int		i;
	char	*tmp;

	if (args[0] == 0)
		return ;
	i = 0;
	while (i < msh_num_builtins())
		if (!is_builting(&args, &i, var))
			return ;
	i = 0;
	while ((tmp = ft_strchr(args[i], '=')) && args[i][0] != '=')
	{
		*tmp = 0;
		tmp++;
		if (var->envp[get_var(args[i], var->envp)])
			set_var(args[i], tmp, var->envp);
		else
			set_var(args[i], tmp, var->local);
		i++;
	}
	if (args[i])
		msh_launch(&args[i], var);
	else
		(var->ret = 1);
}
