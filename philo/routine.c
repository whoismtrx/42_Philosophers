/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:36:38 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/13 20:03:52 by orekabe          ###   ########.fr       */
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
		data->repeat++;
		ft_is_sleeping(data);
		ft_is_thinking(data);
	}
	return (NULL);
}
