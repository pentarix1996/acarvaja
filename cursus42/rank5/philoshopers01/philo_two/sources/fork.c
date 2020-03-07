/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 07:18:34 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/07 03:40:31 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	lock_forks(t_table *table)
{
	if (!sem_wait(table->forks.sem))
		table->forks.value--;
	if (!sem_wait(table->forks.sem))
		table->forks.value--;
}

void	free_forks(t_table *table)
{
	if (!sem_post(table->forks.sem))
		table->forks.value++;
	usleep(100);
	if (!sem_post(table->forks.sem))
		table->forks.value++;
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
