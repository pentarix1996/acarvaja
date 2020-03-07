/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:54:08 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/07 03:41:24 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_dead(t_table *table)
{
	set_actual_state(table, p_dead);
	print_info(get_actual_philosopher(table));
	ft_putstr(" ☠Murio...☠\n");
	exit(0);
}

void	do_sleep_action(t_table *table)
{
	if (is_wake_up(table))
	{
		ft_putstr("\n");
		print_info(get_actual_philosopher(table));
		ft_putstr(" Se desperto! ⏰\n");
		set_actual_state(table, p_thinking);
		table->first_sleep = 0;
		action(table);
	}
	else
	{
		if (!table->first_sleep)
		{
			ft_putstr("Esperando a que alguien se despierte 💤💤💤\n");
			table->first_sleep = 1;
		}
	}
}

void	do_eating_action(t_table *table)
{
	print_info(get_actual_philosopher(table));
	ft_putstr(" Esta comiendo 🍝\n");
	usleep(table->philosophers[table->turn].time_to_eat * 1000);
	print_info(get_actual_philosopher(table));
	ft_putstr(" Termino de comer 😋\n");
	print_info(get_actual_philosopher(table));
	ft_putstr(" Se pone a dormir 🛌\n");
	free_forks(table);
	add_eat(&table->philosophers[table->turn]);
	table->philosophers[table->turn].last_eat = get_time_ms();
	set_actual_state(table, p_sleep);
	table->philosophers[table->turn].last_sleep = get_time_ms();
}
