/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/12/26 18:29:48 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *add)
{
	t_data	*data;

	data = add;
	if (data->id % 2 == 0)
		usleep(50);
	while (1)
	{
		ft_taken_a_fork(data);
		ft_is_eating(data);
		ft_is_sleeping(data);
		ft_is_thinking(data);
		pthread_mutex_lock(&data->philo_d->m_death);
		data->repeat++;
		pthread_mutex_unlock(&data->philo_d->m_death);
	}
	return (NULL);
}
