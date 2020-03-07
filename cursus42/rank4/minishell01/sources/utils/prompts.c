/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:35:08 by cmunoz-r          #+#    #+#             */
/*   Updated: 2020/02/19 14:13:57 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	command_not_found(char *command)
{
	ft_printf("Comando no encontrado: \e[1;31m");
	ft_printf(ft_strjoin(command, "\e[0;0m "));
	ft_printf(" %s\n", strerror(errno));
	exit(127);
}

void	permission_denied(char *command)
{
	ft_printf("Ocurrió un fallo con el comando: \e[1;31m");
	ft_printf(ft_strjoin(command, "\e[0;0m "));
	ft_printf("%s\n", strerror(errno));
	exit(126);
}

void	display_prompt(void)
{
	ft_printf("\e[1;38;5;39mMi\e[38;5;75mni\e[38;5;111msh");
	ft_printf("\e[38;5;147mel\e[38;5;183ml →\e[00;m ");
}

void	put_title(void)
{
	ft_printf("\n");
	ft_printf("%5c\e[1;38;5;183m  __    __     __     __   __     __   ", ' ');
	ft_printf("  ______     __  __     ______     __         __        ", ' ');
	ft_printf("\e[0m\n", ' ');
	ft_printf("%5c\e[1;38;5;147m /\\ \"-./  \\   /\\ \\   /\\ \"-.\\ \\", ' ');
	ft_printf("   /\\ \\   /\\  ___\\   /\\ \\_\\ \\   /\\  ___\\   ", ' ');
	ft_printf("/\\ \\       /\\ \\ \e[0m\n", ' ');
	ft_printf("%5c\e[1;38;5;111m \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ ", ' ');
	ft_printf("\\-.  \\  \\ \\ \\  \\ \\___  \\  \\ \\  __ \\  \\ ", ' ');
	ft_printf("\\  __\\   \\ \\ \\____  \\ \\ \\____\e[0m\n", ' ');
	ft_printf("%5c\e[1;38;5;75m  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\", ' ');
	ft_printf("\\\"\\_\\  \\ \\_\\  \\/\\_____\\  \\ \\_\\ \\_\\  ", ' ');
	ft_printf("\\ \\_____\\  \\ \\_____\\  \\ \\_____\\\e[0m\n", ' ');
	ft_printf("%5c\e[1;38;5;39m   \\/_/  \\/_/   \\/_/   \\/_/ ", ' ');
	ft_printf("\\/_/   \\/_/   \\/_____/   \\/_/\\/_/   \\/_", ' ');
	ft_printf("____/   \\/_____/   \\/_____/\e[0m\n\n", ' ');
}
