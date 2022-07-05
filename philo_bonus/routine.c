/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/05 04:48:33 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_routine(t_data *data)
{
	if (pthread_create(&data->philo_d->t_death, NULL, &ft_is_dead, data))
		return ;
	pthread_detach(data->th_philo);
	while (1)
	{
		ft_taken_a_fork(data);
		ft_is_eating(data);
		data->repeat++;
		ft_is_sleeping(data);
		ft_is_thinking(data);
	}
	return ;
}
