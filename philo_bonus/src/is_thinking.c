/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:21:00 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 17:36:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_is_thinking(t_data *data)
{
	sem_wait(data->philo_d->s_death);
	ft_get_state_time(data);
	printf("%lld %d is thinking\n", data->state_time, data->id);
	sem_post(data->philo_d->s_death);
	usleep(100);
}
