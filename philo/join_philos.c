/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:38:26 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/29 00:07:45 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_d->n_philos)
	{
		pthread_detach(data[i].th_philo);
		i++;
	}
	pthread_join(data->philo_d->t_death, NULL);
	i = 0;
	while (i < data->philo_d->n_philos)
	{
		pthread_mutex_destroy(&data->philo_d->m_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->philo_d->m_death);
}