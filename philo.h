/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:34:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/22 03:49:40 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int				n_philos;
	int				n_forks;
	long long		t_to_die;
	long long		t_to_eat;
	long long		t_to_sleep;
	int				n_t_eat;
	pthread_t		*th_philos;
	pthread_mutex_t	*m_forks;
}				t_philo;

int	ft_atoi(char *str);
int	ft_isdigit(char c);
int	ft_check_error(t_philo *philo, int argc, char **argv);

#endif