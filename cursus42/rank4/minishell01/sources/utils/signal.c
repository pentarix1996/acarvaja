/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:13:39 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/18 11:44:13 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

void	signal_interrupt_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_prompt();
		signal(SIGINT, signal_interrupt_handler);
	}
}

void	proc_signal_quit_hundler(int signo)
{
	if (signo == SIGQUIT)
	{
		ft_putstr("Quit\n");
		signal(SIGINT, signal_quit_hundler);
	}
}

void	signal_quit_hundler(int signo)
{
	if (signo == SIGQUIT)
		signal(SIGINT, signal_quit_hundler);
}
