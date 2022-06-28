/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 05:01:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 05:47:28 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_left_fork(t_data *data)
{
	if (data->id == data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_forks[0]);
		pthread_mutex_lock(&data->philo_d->m_death);
		ft_get_state_time(data);
		pthread_mutex_unlock(&data->philo_d->m_death);
		pthread_mutex_lock(&data->philo_d->m_death);
		printf("%lld philo %d has taken a fork\n", data->state_time, data->id);
		pthread_mutex_unlock(&data->philo_d->m_death);
	}
	else
	{
		pthread_mutex_lock(&data->philo_d->m_forks[data->id]);
		pthread_mutex_lock(&data->philo_d->m_death);
		ft_get_state_time(data);
		pthread_mutex_unlock(&data->philo_d->m_death);
		pthread_mutex_lock(&data->philo_d->m_death);
		printf("%lld philo %d has taken a fork\n", data->state_time, data->id);
		pthread_mutex_unlock(&data->philo_d->m_death);
	}
}

void	ft_right_fork(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_forks[data->id - 1]);
	pthread_mutex_lock(&data->philo_d->m_death);
	ft_get_state_time(data);
	pthread_mutex_unlock(&data->philo_d->m_death);
	pthread_mutex_lock(&data->philo_d->m_death);
	printf("%lld philo %d has taken a fork\n", data->state_time, data->id);
	pthread_mutex_unlock(&data->philo_d->m_death);
}

void	ft_taken_a_fork(t_data *data)
{
	if (data->id % 2 == 0)
	{
		ft_left_fork(data);
		ft_right_fork(data);
	}
	else
	{
		ft_right_fork(data);
		ft_left_fork(data);
	}
}
