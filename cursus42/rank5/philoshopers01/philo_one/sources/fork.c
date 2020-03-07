/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:18:34 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/06 21:37:00 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	lock_forks(t_table *table)
{
	pthread_mutex_lock(&table->forks[table->turn].mutex);
	table->forks[table->turn].fork_state = 1;
	if (table->turn == 0)
	{
		table->forks[table->num_philo - 1].fork_state = 1;
		pthread_mutex_lock(&table->forks[table->num_philo - 1].mutex);
	}
	else
	{
		table->forks[table->turn - 1].fork_state = 1;
		pthread_mutex_lock(&table->forks[table->turn - 1].mutex);
	}
}

void	free_forks(t_table *table)
{
	pthread_mutex_unlock(&table->forks[table->turn].mutex);
	table->forks[table->turn].fork_state = 0;
	if (table->turn == 0)
	{
		table->forks[table->num_philo - 1].fork_state = 0;
		pthread_mutex_unlock(&table->forks[table->num_philo - 1].mutex);
	}
	else
	{
		table->forks[table->turn - 1].fork_state = 0;
		pthread_mutex_unlock(&table->forks[table->turn - 1].mutex);
	}
}

t_fork	*fill_forks(t_fork *forks, int num_forks)
{
	int i;

	if (!(forks = malloc(sizeof(t_fork) * num_forks)))
		return (0);
	i = -1;
	while (++i < num_forks)
	{
		forks[i].fork_state = 0;
		pthread_mutex_init(&forks[i].mutex, NULL);
	}
	return (forks);
}

void	try_take_forks(t_table *table)
{
	if (check_if_live(get_actual_philosopher(table)) && can_eat(table))
	{
		if (is_max_eat_enb(table))
		{
			if (table->philosophers[table->turn].eat_count >= table->eat_max)
			{
				table->philosophers[table->turn].state = p_end_eat;
				if (is_last(table))
				{
					ft_putstr("Todos los filosofos terminaron de comer! 👍\n");
					exit(EXIT_SUCCESS);
				}
				ft_putstr("\nEl filosofo (");
				print_nbr(table->philosophers[table->turn].num);
				ft_putstr(") comio el maximo de veces 🙏\n");
				return ;
			}
		}
		print_info(get_actual_philosopher(table));
		ft_putstr(" cogio los tenedores 🍽\n");
		set_actual_state(table, p_eating);
		lock_forks(table);
	}
	else if (!check_if_live(get_actual_philosopher(table)))
		philo_dead(table);
}
