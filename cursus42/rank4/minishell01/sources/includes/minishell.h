/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:46:09 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/24 16:42:55 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H
# define _MINISHELL_H

# define SH_TOK_DELIM " \t\r\n\a"
# define PATH_MAX 2500
# define MAX_PITS 100
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include "../../ft_printf/ft_printf.h"
# include "sys/errno.h"

typedef struct		s_command
{
	char			***args;
	char			***redir;
	int				fpipe;
	int				count;
}					t_command;

typedef struct		s_var
{
	char			**envp;
	char			**local;
	short unsigned	ret;
}					t_var;

extern char	*g_builtin_str[7];
extern void	(*g_builtin_func[7]) (char **, t_var *);

void				check_stty(char **envp);
void				msh_loop(t_var *var);
int					get_var(char *variable, char **array);
void				set_var(char *variable, char *value, char **array);
char				*get_var_value(int var_len, char *variable, char **array);
void				erase_var(char *variable, char **array);
int					parse_var_len(char *variable);
int					ft_strchr_count(const char *str, int asc);
char				**msh_parse_line(char **line, t_var *var);
void				msh_read_line(char **line);
int					msh_var_swap(char *str, char **ptr, t_var *var);
int					msh_bar_count(char *str, int *i);
char				*msh_parse_path(char *path);
int					check_variable(char *variable);
void				msh_cd(char **args, t_var *var);
void				msh_echo(char **args, t_var *var);
void				msh_exit(char **args, t_var *var);
void				msh_pwd(char **args, t_var *var);
void				msh_env(char **args, t_var *var);
void				msh_export(char **args, t_var *var);
void				msh_unset(char **args, t_var *var);
void				proc_signal_handler(int signo);
void				signal_interrupt_handler(int signo);
void				signal_quit_hundler(int signo);
void				proc_signal_quit_hundler(int signo);
void				display_prompt();
int					count_commands(char *line, char c, char d);
int					parse_commands(char *line, char c, char d);
void				command_not_found(char *command);
void				permission_denied(char *command);
void				free_args(t_command *commands, int count);
void				free_redir(t_command *commands, int count);
void				free_double_array(char **array);
void				fill_redir(int k, char *aux, t_command *commands
								, t_var *var);
t_command			parse_redir(char *aux, t_var *var);
char				**fill_pipe_redir(int k, char *new_line, t_var *var);
void				parse_pipe_redir(t_command *commands, int i, char **line
										, t_var *var);
void				msh_execute(char **args, t_var *var);
void				put_title(void);
void				redir(t_command commands, t_var *var, int j, int ispipe);
void				msh_execute_pipe(t_command commands, t_var *var);
void				do_redirect(int fd, char **args, t_var *var, int ispipe);
int					exist_pipe(t_command **commands, char *line,
								int com_i, t_var *var);
void				choose_execute(t_command *commands, char *aux,
									int i, t_var *var);
t_command			*fill_mul_commands(int *count_com, int count,
										char *line, t_var *var);
t_command			*fill_commands(char *line, int *count_com, t_var *var);

#endif
