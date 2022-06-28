/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:32:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 05:49:01 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_is_dead(void *add)
{
	long long	death;
	t_data		*data;
	int			i;

	i = 0;
	death = 0;
	data = add;
	while (i < data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_death);
		ft_get_state_time(&data[i]);
		pthread_mutex_unlock(&data->philo_d->m_death);
		death = data[i].state_time - data[i].last_meal;
		if (death >= data->philo_d->t_to_die)
		{
			data->philo_d->life = 0;
			pthread_mutex_lock(&data->philo_d->m_death);
			printf("%lld philo %d is dead\n", data[i].state_time, data[i].id);
			break ;
		}
		if (i + 1 == data->philo_d->n_philos)
			i = -1;
		i++;
	}
	return (NULL);
}
