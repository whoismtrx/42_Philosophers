/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 01:31:06 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/13 23:34:04 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_last_meal(t_data *data)
{
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	data->last_meal = (c_time.tv_sec * 1000) + (c_time.tv_usec / 1000);
	data->last_meal -= data->philo_d->start_time;
}

void	ft_get_state_time(t_data *data)
{
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	data->state_time = (c_time.tv_sec * 1000) + (c_time.tv_usec / 1000);
	data->state_time -= data->philo_d->start_time;
}

void	ft_get_start_time(t_data *data)
{
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	data->philo_d->start_time = (c_time.tv_sec * 1000)
		+ (c_time.tv_usec / 1000);
}
