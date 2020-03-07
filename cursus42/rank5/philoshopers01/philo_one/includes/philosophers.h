/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:41:54 by acarvaja          #+#    #+#             */
/*   Updated: 2020/03/06 21:12:12 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define SLEEP_WAIT 55000
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef enum		e_states
{
	p_sleep,
	p_eating,
	p_thinking,
	p_dead,
	p_end_eat
}					t_states;

typedef struct		s_fork
{
	pthread_mutex_t mutex;
	int				fork_state;
}					t_fork;

typedef struct		s_philo
{
	int				num;
	pthread_t		thread;
	int				state;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	uint64_t		last_eat;
	uint64_t		last_sleep;
	int				eat_count;
}					t_philo;

typedef struct		s_table
{
	t_philo			*philosophers;
	t_fork			*forks;
	int				turn;
	int				num_philo;
	int				first_sleep;
	int				eat_max;
}					t_table;

int					ft_strlen(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(char *str);
void				print_nbr(uint64_t nbr);
int					is_live(t_philo *philo);
void				add_eat(t_philo *philo);
int					check_if_live(t_philo *philo);
void				print_info(t_philo *philo);
t_philo				*fill_philos(t_philo *philo, char **argv);
uint64_t			get_time_ms();
int					is_max_eat_enb(t_table *table);
int					can_eat(t_table *table);
t_philo				*get_actual_philosopher(t_table *table);
int					get_actual_state(t_table *table);
int					is_live(t_philo *philo);
int					is_wake_up(t_table *table);
int					is_last(t_table *table);
void				lock_forks(t_table *table);
void				free_forks(t_table *table);
t_fork				*fill_forks(t_fork *forks, int num_forks);
void				set_actual_state(t_table *table, int state);
void				try_take_forks(t_table *table);
void				philo_dead(t_table *table);
void				do_sleep_action(t_table *table);
void				do_eating_action(t_table *table);
void				action(t_table *table);

#endif
