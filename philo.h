/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:34:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 04:52:56 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				n_philos;
	int				n_forks;
	long long		t_to_die;
	long long		t_to_eat;
	long long		t_to_sleep;
	int				n_t_eat;
	pthread_mutex_t	*m_forks;
	long long		start_time;
}				t_philo;

typedef struct s_data
{
	t_philo		*philo_d;
	int			id;
	pthread_t	th_philo;
	long long		state_time;
	long long		last_meal;
}				t_data;

int	ft_atoi(char *str);
int	ft_isdigit(char c);
int	ft_check_error(t_philo *philo, int argc, char **argv);
void	ft_taken_a_fork(t_data *data);
void	ft_is_eating(t_data *data);
void	ft_is_sleeping(t_data *data);
void	ft_is_thinking(t_data *data);
void	ft_get_start_time(t_data *data);
void	ft_get_state_time(t_data *data);
void	ft_get_last_meal(t_data *data);

#endif