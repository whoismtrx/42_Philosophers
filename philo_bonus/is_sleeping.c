/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:53:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/05 04:37:53 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_is_sleeping(t_data *data)
{
	pthread_mutex_lock(&data->philo_d->m_death);
	ft_get_state_time(data);
	pthread_mutex_unlock(&data->philo_d->m_death);
	pthread_mutex_lock(&data->philo_d->m_death);
	printf("%lld %d is sleeping\n", data->state_time, data->id);
	pthread_mutex_unlock(&data->philo_d->m_death);
	ft_mysleep(data->philo_d->t_to_sleep);
}
