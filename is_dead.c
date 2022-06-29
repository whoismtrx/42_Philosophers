/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:32:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/29 05:52:07 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_is_dead(void *add)
{
	t_data		*data;
	int			i;

	i = 0;
	data = add;
	while (i < data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_death);
		ft_get_state_time(&data[i]);
		pthread_mutex_unlock(&data->philo_d->m_death);
		data->philo_d->death = data[i].state_time - data[i].last_meal;
		if (data->philo_d->death >= data->philo_d->t_to_die && data->philo_d->a_repeat != data->philo_d->n_t_eat)
		{
			pthread_mutex_lock(&data->philo_d->m_death);
			printf("%lld philo %d is dead\n", data[i].state_time, data[i].id);
			return (NULL);
		}
		if (data->philo_d->a_repeat == data->philo_d->n_t_eat)
			return (NULL);
		if (i + 1 == data->philo_d->n_philos)
			i = -1;
		i++;
	}
	return (NULL);
}
