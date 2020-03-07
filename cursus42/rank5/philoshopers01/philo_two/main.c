/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:40:40 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/06 21:41:57 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	action(t_table *table)
{
	if (get_actual_state(table) == p_end_eat)
		return ;
	if (get_actual_state(table) == p_thinking)
		try_take_forks(table);
	if (get_actual_state(table) == p_eating &&
			is_live(get_actual_philosopher(table)))
		do_eating_action(table);
	else if (get_actual_state(table) == p_sleep &&
			is_live(get_actual_philosopher(table)))
		do_sleep_action(table);
	if (!table->first_sleep)
		ft_putstr("\n");
	free_forks(table);
}

void	next_action(t_table *table)
{
	if (is_live(&table->philosophers[table->turn]))
		action(table);
}

void	init_table(t_table *table, int argc, char **argv, t_fork *forks)
{
	table->forks = *forks;
	table->turn = 0;
	table->num_philo = ft_atoi(argv[1]);
	table->first_sleep = 0;
	if (argc == 6)
		table->eat_max = ft_atoi(argv[5]);
	else
		table->eat_max = -1;
}

void	init_philos_forks(t_philo **philosophers, char **argv, t_fork *forks)
{
	*philosophers = fill_philos(*philosophers, argv);
	sem_unlink(SEMAPHORE_FORK);
	forks->sem = sem_open(SEMAPHORE_FORK, O_CREAT, 0666, ft_atoi(argv[1]));
	forks->value = ft_atoi(argv[1]);
}

int		main(int argc, char **argv)
{
	t_philo *philosophers;
	t_fork	forks;
	t_table	table;

	philosophers = 0;
	if (argc < 5)
		ft_putstr("Error: Faltan argumentos\n");
	else if (argc > 6)
		ft_putstr("Error: Demasiados argumentos\n");
	else
	{
		init_philos_forks(&philosophers, argv, &forks);
		table.philosophers = philosophers;
		init_table(&table, argc, argv, &forks);
		while (philosophers[table.turn].state != p_dead)
		{
			pthread_create(&table.philosophers[table.turn].thread, NULL,
				(void *)next_action, (void *)&table);
			pthread_join(philosophers[table.turn].thread, NULL);
			if (++table.turn >= table.num_philo)
				table.turn = 0;
		}
	}
	return (0);
}
