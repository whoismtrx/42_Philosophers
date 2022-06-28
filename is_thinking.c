/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:21:00 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 03:56:43 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_thinking(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_death);
	ft_get_state_time(data);
	pthread_mutex_unlock(&data->philo_d->m_death);
	pthread_mutex_lock(&data->philo_d->m_death);
	printf("%lld philo %d is thinking\n",data->state_time, data->id);
	pthread_mutex_unlock(&data->philo_d->m_death);
}