/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:18:55 by acarvaja          #+#    #+#             */
/*   Updated: 2020/01/28 04:06:03 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
  Function Declarations for builtin shell commands:
 */
int msh_cd(char **args);
int msh_echo(char **args);
int msh_exit(char **args);
int msh_pwd(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] =
{
	"cd",
	"echo",
	"pwd",
	"exit"
};

int (*builtin_func[]) (char **) =
{
	&msh_cd,
	&msh_echo,
	&msh_pwd,
	&msh_exit
};

int msh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int msh_cd(char **args)
{
	if (args[1] == 0)
		ft_printf("Se esperaba un argumento para el comando: \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Minishell"); //Esto se deberia cambiar
	}
	return (1);
}

int msh_echo(char **args)
{
	int i;

	if (args[1])
	{
		i = 1;
		while (args[i])
		{
			ft_printf("%s", args[i++]);
			ft_printf(" ");
		}
	}
	ft_printf("\n");
	return (1);
}

int msh_pwd(char **args)
{
	char	buf[PATH_MAX + 1];

	if (args[1])
		ft_printf("Demasiados argumentos para el comando %s\n", args[0]);
	else
		ft_printf("%s\n", getcwd(buf, PATH_MAX));
	return (1);
}

/*int msh_help(char **args)
{
	int i;
	(void)args;
	printf("Stephen Brennan's LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < msh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return 1;
}*/

int msh_exit(char **args)
{
	(void)args;
	return (0);
}

int msh_launch(char **args, char **envp)
{
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	// Child process
		if (execve(args[0], args, envp) == -1)
		{
			ft_printf("%s: comando no encontrado\nMinishell > ", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		// Error forking
		ft_printf("Minishell --> Ocurrio un error");
	else
	{
	// Parent process
	while (!WIFEXITED(status) && !WIFSIGNALED(status))
		wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int msh_execute(char **args, char **envp)
{
	int i;

	if (args[0] == 0)
		return (1);
	i = 0;
	while (i < msh_num_builtins())
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
		i++;
	}
	return msh_launch(args, envp);
}

char *msh_read_line(void)
{
	char *line = 0;
	get_next_line(0, &line);
	return (line);
}

char **msh_split_line(char *line)
{
	char **args;

	if (!(args = malloc(64 * sizeof(char*))))
	{
		ft_printf("Minishell --> Error al alocar memoria\n");
		exit(EXIT_FAILURE);
	}
	args = ft_split(line, ' ');
	return (args);
}

void put_title()
{
	ft_printf("\n");
	ft_printf("%5c  __    __     __     __   __     __     ______     __  __     ______     __         __        \n", ' ');
	ft_printf("%5c /\\ \"-./  \\   /\\ \\   /\\ \"-.\\ \\   /\\ \\   /\\  ___\\   /\\ \\_\\ \\   /\\  ___\\   /\\ \\       /\\ \\ \n", ' ');
	ft_printf("%5c \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\  \\ \\ \\  \\ \\___  \\  \\ \\  __ \\  \\ \\  __\\   \\ \\ \\____  \\ \\ \\____\n", ' ');
	ft_printf("%5c  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\\\\"\\_\\  \\ \\_\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\\n", ' ');
	ft_printf("%5c   \\/_/  \\/_/   \\/_/   \\/_/ \\/_/   \\/_/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/\n\n", ' ');
	ft_printf("%15c  █████╗  ██████╗ █████╗ ██████╗ ██╗   ██╗ █████╗      ██╗ █████╗    \n", ' ');
	ft_printf("%15c ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║██╔══██╗     ██║██╔══██╗   \n", ' ');
	ft_printf("%15c ███████║██║     ███████║██████╔╝██║   ██║███████║     ██║███████║   \n", ' ');
	ft_printf("%15c ██╔══██║██║     ██╔══██║██╔══██╗╚██╗ ██╔╝██╔══██║██   ██║██╔══██║   \n", ' ');
	ft_printf("%15c ██║  ██║╚██████╗██║  ██║██║  ██║ ╚████╔╝ ██║  ██║╚█████╔╝██║  ██║   \n", ' ');
	ft_printf("%15c ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝  ╚═══╝  ╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝   \n\n", ' ');
	ft_printf("%15c                             ██╗   ██╗                               \n", ' ');
	ft_printf("%15c                             ╚██╗ ██╔╝                               \n", ' ');
	ft_printf("%15c                              ╚████╔╝                                \n", ' ');
	ft_printf("%15c                               ╚██╔╝                                 \n", ' ');
	ft_printf("%15c                                ██║                                  \n", ' ');
	ft_printf("%15c                                ╚═╝                                  \n\n", ' ');
	ft_printf("%15c  ██████╗███╗   ███╗██╗   ██╗███╗   ██╗ ██████╗ ███████╗     ██████╗ \n", ' ');
	ft_printf("%15c ██╔════╝████╗ ████║██║   ██║████╗  ██║██╔═══██╗╚══███╔╝     ██╔══██╗\n", ' ');
	ft_printf("%15c ██║     ██╔████╔██║██║   ██║██╔██╗ ██║██║   ██║  ███╔╝█████╗██████╔╝\n", ' ');
	ft_printf("%15c ██║     ██║╚██╔╝██║██║   ██║██║╚██╗██║██║   ██║ ███╔╝ ╚════╝██╔══██╗\n", ' ');
	ft_printf("%15c ╚██████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║╚██████╔╝███████╗     ██║  ██║\n", ' ');
	ft_printf("%15c  ╚═════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝     ╚═╝  ╚═╝\n", ' ');
}

void msh_loop(char **envp)
{
	char *line;
	char **args;
	int status;

	status = 1;	
	put_title();
	while (status)
	{
		ft_printf("Minishell > ");
		line = msh_read_line();
		args = msh_split_line(line);
		status = msh_execute(args, envp);
		free(line);
		free(args);
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc == 1)
		msh_loop(envp);
	else
		system("echo hola");
	return (0); 
}
