/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 05:01:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/26 00:44:49 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_left_fork(t_data *data)
{
	if (data->id == data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_forks[0]);
		printf("%d has taken a fork\n", data->id);
	}
	else
	{
		pthread_mutex_lock(&data->philo_d->m_forks[data->id]);
		printf("%d has taken a fork\n", data->id);
	}
}

void	ft_right_fork(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_forks[data->id - 1]);
	printf("%d has taken a fork\n", data->id);
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
