/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:13:58 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 05:46:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_eating(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_death);
	ft_get_state_time(data);
	pthread_mutex_unlock(&data->philo_d->m_death);
	ft_get_last_meal(data);
	pthread_mutex_lock(&data->philo_d->m_death);
	printf("%lld philo %d is eating\n", data->state_time, data->id);
	pthread_mutex_unlock(&data->philo_d->m_death);
	usleep(data->philo_d->t_to_eat * 1000);
	if (data->id == data->philo_d->n_philos)
	{
		pthread_mutex_unlock(&data->philo_d->m_forks[0]);
		pthread_mutex_unlock(&data->philo_d->m_forks[data->id - 1]);
	}
	else
	{
		pthread_mutex_unlock(&data->philo_d->m_forks[data->id - 1]);
		pthread_mutex_unlock(&data->philo_d->m_forks[data->id]);
	}
}
