/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:13:58 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/26 03:32:32 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_eating(t_data *data)
{
	printf("%d is eating\n", data->id);
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