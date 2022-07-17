/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:08:06 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 16:45:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int			n_philos;
	int			n_forks;
	long long	t_to_die;
	long long	t_to_eat;
	long long	t_to_sleep;
	int			n_t_eat;
	long long	start_time;
	int			a_repeat;
	int			*pid;
	sem_t		*s_forks;
	sem_t		*s_death;
	int			mpid;
}				t_philo;

typedef struct s_data
{
	t_philo		*philo_d;
	pthread_t	t_death;
	int			id;
	long long	state_time;
	long long	last_meal;
	int			repeat;
	long long	death;
}				t_data;

int		ft_check_error(t_philo *philo, int argc, char **argv);
int		ft_atoi(char *str);
int		ft_isdigit(char c);
void	ft_init_data(t_philo *philo, t_data *data);
void	ft_create_philos(t_data *data, t_philo *philo);
void	ft_join_philos(t_data *data);
void	ft_routine(t_data *data);
void	ft_get_last_meal(t_data *data);
void	ft_get_state_time(t_data *data);
void	ft_get_start_time(t_data *data);
void	*ft_is_dead(void *add);
void	ft_taken_a_fork(t_data *data);
void	ft_is_eating(t_data *data);
void	ft_is_sleeping(t_data *data);
void	ft_is_thinking(t_data *data);
void	ft_mysleep(long long time);

#endif