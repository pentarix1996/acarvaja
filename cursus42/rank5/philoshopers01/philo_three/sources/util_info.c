/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:19:35 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/06 21:38:08 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_live(t_philo *philo)
{
	return (philo->state != p_dead);
}

int	is_wake_up(t_table *table)
{
	return (get_time_ms() - table->philosophers[table->turn].last_sleep >=
					(uint64_t)table->philosophers[table->turn].time_to_sleep);
}

int	is_last(t_table *table)
{
	return (table->turn == table->num_philo - 1);
}
