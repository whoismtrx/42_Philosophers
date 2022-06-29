/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/29 05:46:03 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *add)
{
	t_data	*data;

	data = add;
	data->last_meal = 0;
	data->state_time = 0;
	if (data->id % 2 == 0)
		ft_mysleep(1);
	while (1)
	{
		ft_taken_a_fork(data);
		ft_is_eating(data);
		data->repeat++;
		if(data->repeat == data->philo_d->n_t_eat)
		{
			data->philo_d->a_repeat++;
			return (NULL);
		}
		ft_is_sleeping(data);
		ft_is_thinking(data);
	}
	return (NULL);
}
