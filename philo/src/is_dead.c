/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:32:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/12/26 18:28:12 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(t_data *data, int i)
{
	if (data->philo_d->a_repeat == data->philo_d->n_t_eat)
	{
		pthread_mutex_lock(&data->philo_d->m_death);
		return (1);
	}
	if (data[i].death >= data->philo_d->t_to_die)
	{
		pthread_mutex_lock(&data->philo_d->m_death);
		printf("%lld %d died\n", data[i].state_time, data[i].id);
		return (1);
	}
	return (0);
}

void	*ft_is_dead(void *add)
{
	t_data		*data;
	int			i;

	i = 0;
	data = add;
	ft_mysleep(1);
	while (i < data->philo_d->n_philos)
	{
		pthread_mutex_lock(&data->philo_d->m_death);
		ft_get_state_time(&data[i]);
		pthread_mutex_unlock(&data->philo_d->m_death);
		pthread_mutex_lock(&data->philo_d->m_death);
		data[i].death = data[i].state_time - data[i].last_meal;
		pthread_mutex_unlock(&data->philo_d->m_death);
		if (ft_check(data, i))
			return (NULL);
			pthread_mutex_lock(&data->philo_d->m_death);
		if (data[i].repeat == data->philo_d->n_t_eat)
		{
			data[i].philo_d->a_repeat++;
		}
			pthread_mutex_unlock(&data->philo_d->m_death);
		if (i + 1 == data->philo_d->n_philos)
			i = -1;
		i++;
	}
	return (NULL);
}
