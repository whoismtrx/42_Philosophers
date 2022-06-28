/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 05:50:00 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *add)
{
	t_data	*data;

	data = add;
	data->last_meal = 0;
	data->state_time = 0;
	while (data->philo_d->life)
	{
		ft_taken_a_fork(data);
		ft_is_eating(data);
		ft_is_sleeping(data);
		ft_is_thinking(data);
	}
	return (NULL);
}
