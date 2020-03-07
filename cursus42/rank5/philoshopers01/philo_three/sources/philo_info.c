/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:11:36 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/07 03:36:59 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	add_eat(t_philo *philo)
{
	philo->eat_count++;
}

int		check_if_live(t_philo *philo, int mode)
{
	return (mode == MONITORING_MODE ? get_time_ms() - philo->last_eat
			<= (uint64_t)philo->time_to_die : get_time_ms() - philo->last_eat
			- philo->time_to_eat <= (uint64_t)philo->time_to_die);
}

void	set_actual_state(t_table *table, int state)
{
	table->philosophers[table->turn].state = state;
}

void	print_info(t_philo *philo)
{
	print_nbr(get_time_ms());
	ft_putstr(" El filosofo 👳  ");
	print_nbr(philo->num);
}

t_philo	*fill_philos(t_philo *philo, char **argv)
{
	int i;

	if (!(philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]))))
		return (0);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].num = i;
		philo[i].state = p_thinking;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		philo[i].last_eat = get_time_ms();
		philo[i].last_sleep = get_time_ms();
		philo[i].eat_count = 0;
		philo[i].pid = 0;
		i++;
	}
	return (philo);
}
