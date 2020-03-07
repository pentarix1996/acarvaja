/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:15:08 by acarvaja          #+#    #+#             */
/*   Updated: 2020/02/28 07:37:30 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

uint64_t	get_time_ms(void)
{
	struct timeval timev;

	gettimeofday(&timev, NULL);
	return ((timev.tv_sec * (uint64_t)1000) + (timev.tv_usec / 1000));
}

int			is_max_eat_enb(t_table *table)
{
	return (table->eat_max >= 0);
}

int			can_eat(t_table *table)
{
	if (table->turn == 0)
		return (!table->forks[table->turn].fork_state &&
				!table->forks[table->num_philo - 1].fork_state);
	else
		return (!table->forks[table->turn].fork_state &&
				!table->forks[table->turn - 1].fork_state);
}

t_philo		*get_actual_philosopher(t_table *table)
{
	return (&table->philosophers[table->turn]);
}

int			get_actual_state(t_table *table)
{
	return (table->philosophers[table->turn].state);
}
