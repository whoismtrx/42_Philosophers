/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:37:47 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/16 23:06:28 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	ft_get_start_time(data);
	while (i < data->philo_d->n_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
			ft_routine(data + i);
		i++;
	}
}
