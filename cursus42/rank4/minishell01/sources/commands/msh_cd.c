/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:24:58 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/20 13:55:28 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cd_move(char **pwd, char **old_pwd, char **args, t_var *var)
{
	struct stat	data;

	lstat(*pwd, &data);
	if (chdir(*pwd) != 0)
		ft_printf("%s\n", strerror(errno));
	if (!errno)
	{
		set_var("OLD_PWD", *old_pwd, var->envp);
		if (!S_ISLNK(data.st_mode) || !(ft_strcmp(args[1], "-P")))
		{
			free(*pwd);
			*pwd = getcwd(NULL, 0);
			set_var("PWD", *pwd, var->envp);
		}
		else
			set_var("PWD", *pwd, var->envp);
		return (0);
	}
	free(*pwd);
	free(*old_pwd);
	return (1);
}

int		cd_arg(char **args, t_var *var)
{
	int			i;
	char		*pwd;
	char		*old_pwd;
	char		*tmp;

	old_pwd = ft_strdup(get_var_value(3, "PWD", var->envp));
	i = 1;
	if (!(ft_strcmp(args[i], "-P")) || (!ft_strcmp(args[i], "-L")))
		i++;
	if (args[1][0] == '/')
		pwd = msh_parse_path(args[i]);
	else
	{
		pwd = ft_strjoin(old_pwd, "/");
		tmp = ft_strjoin(pwd, args[i]);
		free(pwd);
		pwd = msh_parse_path(tmp);
	}
	if (cd_move(&pwd, &old_pwd, args, var))
		return (1);
	free(pwd);
	free(old_pwd);
	return (0);
}

int		cd_no_arg(t_var *var)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(get_var_value(4, "HOME", var->envp));
	if (chdir(tmp) != 0)
		ft_printf("%s\n", strerror(errno));
	if (!errno)
	{
		set_var("OLD_PWD", get_var_value(3, "PWD", var->envp), var->envp);
		set_var("PWD", tmp, var->envp);
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int		cd_minus(t_var *var)
{
	char	*pwd;
	char	*tmp;

	pwd = ft_strdup(get_var_value(3, "PWD", var->envp));
	if (chdir((tmp = ft_strdup(get_var_value(7, "OLD_PWD", var->envp)))) != 0)
		ft_printf("%s\n", strerror(errno));
	if (!errno)
	{
		set_var("PWD", tmp, var->envp);
		set_var("OLD_PWD", pwd, var->envp);
		ft_printf("%s\n", tmp);
		free(pwd);
		free(tmp);
		return (0);
	}
	free(pwd);
	return (1);
}

void	msh_cd(char **args, t_var *var)
{
	if (!args[1])
		var->ret = cd_no_arg(var);
	else if (!ft_strcmp(args[1], "-"))
		var->ret = cd_minus(var);
	else
		var->ret = cd_arg(args, var);
}
