/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:53:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 17:31:10 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_is_sleeping(t_data *data)
{
	sem_wait(data->philo_d->s_death);
	ft_get_state_time(data);
	printf("%lld %d is sleeping\n", data->state_time, data->id);
	sem_post(data->philo_d->s_death);
	ft_mysleep(data->philo_d->t_to_sleep);
}
