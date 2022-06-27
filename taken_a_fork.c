/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 05:01:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 05:47:16 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_left_fork(t_data *data)
{
	if (data->id == data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_forks[0]);
		ft_get_state_time(data);
		printf("%lld philo %d has taken a fork\n",data->state_time, data->id);
	}
	else
	{
		pthread_mutex_lock(&data->philo_d->m_forks[data->id]);
		ft_get_state_time(data);
		printf("%lld philo %d has taken a fork\n",data->state_time, data->id);
	}
}

void	ft_right_fork(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_forks[data->id - 1]);
	ft_get_state_time(data);
	printf("%lld philo %d has taken a fork\n",data->state_time, data->id);
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
