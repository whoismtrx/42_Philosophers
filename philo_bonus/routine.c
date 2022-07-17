/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 04:40:03 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_routine(t_data *data)
{
	if (pthread_create(&data->t_death, NULL, &ft_is_dead, data))
	{
		write(2, "Failed to create thread\n", 24);
		exit (1);
	}
	pthread_detach(data->t_death);
	if (data->id % 2 == 0)
		usleep(50);
	while (1)
	{
		ft_taken_a_fork(data);
		ft_is_eating(data);
		ft_is_sleeping(data);
		ft_is_thinking(data);
		data->repeat++;
	}
	return ;
}
