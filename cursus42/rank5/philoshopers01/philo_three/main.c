/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:40:40 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/07 03:35:39 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	next_action(t_table *table, int mode)
{
	if (is_live(&table->philosophers[table->turn]))
		action(table, mode);
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

void	do_logic_monitoring(t_table *table)
{
	int status;
	int ret;

	status = 0;
	ret = 0;
	if ((table->philosophers[table->turn].pid = fork()) == 0)
	{
		next_action(table, MONITORING_MODE);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(table->philosophers[table->turn].pid, &status, 2);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
		if (ret == DEAD_SIGNAL)
			exit(EXIT_SUCCESS);
	}
	next_action(table, LOGIC_MODE);
}

int		main(int argc, char **argv)
{
	t_philo	*philosophers;
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
		while (is_live(get_actual_philosopher(&table)))
		{
			do_logic_monitoring(&table);
			if (++table.turn >= table.num_philo)
				table.turn = 0;
		}
	}
	return (0);
}
