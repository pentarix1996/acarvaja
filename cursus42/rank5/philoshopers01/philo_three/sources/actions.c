/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:54:08 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/07 03:37:03 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_dead(t_table *table)
{
	set_actual_state(table, p_dead);
	print_info(get_actual_philosopher(table));
	ft_putstr(" ☠Murio...☠\n");
	usleep(table->philosophers->time_to_eat);
	exit(4);
}

void	do_sleep_action(t_table *table, int mode)
{
	if (is_wake_up(table))
	{
		if (mode == MONITORING_MODE)
		{
			ft_putstr("\n");
			print_info(get_actual_philosopher(table));
			ft_putstr(" Se desperto! ⏰\n");
		}
		else
			table->first_sleep = 0;
		set_actual_state(table, p_thinking);
		action(table, mode);
	}
	else
	{
		if (!table->first_sleep)
		{
			if (mode == MONITORING_MODE)
				ft_putstr("Esperando a que alguien se despierte 💤💤💤\n");
			else
				table->first_sleep = 1;
		}
	}
}

void	do_eating_action(t_table *table, int mode)
{
	if (mode == MONITORING_MODE)
	{
		print_info(get_actual_philosopher(table));
		ft_putstr(" Esta comiendo 🍝\n");
		print_info(get_actual_philosopher(table));
		usleep(table->philosophers[table->turn].time_to_eat * 1000);
		ft_putstr(" Termino de comer 😋\n");
		print_info(get_actual_philosopher(table));
		ft_putstr(" Se pone a dormir 🛌\n");
	}
	else
		free_forks(table);
	add_eat(&table->philosophers[table->turn]);
	table->philosophers[table->turn].last_eat = get_time_ms();
	table->philosophers[table->turn].last_sleep = get_time_ms();
	set_actual_state(table, p_sleep);
}

void	action(t_table *table, int mode)
{
	if (get_actual_state(table) == p_end_eat)
		return ;
	if (get_actual_state(table) == p_thinking)
		try_take_forks(table, mode);
	if (get_actual_state(table) == p_eating &&
			is_live(get_actual_philosopher(table)))
		do_eating_action(table, mode);
	else if (get_actual_state(table) == p_sleep &&
			is_live(get_actual_philosopher(table)))
		do_sleep_action(table, mode);
	if (!table->first_sleep && mode == MONITORING_MODE)
		ft_putstr("\n");
}
