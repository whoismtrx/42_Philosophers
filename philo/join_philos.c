/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:38:26 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/14 01:46:26 by orekabe          ###   ########.fr       */
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
	free(data->philo_d->m_forks);
}
