/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:37:47 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 21:48:25 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 0;
	ft_get_start_time(data);
	while (i < data->philo_d->n_philos)
	{
		if (pthread_create(&data[i].th_philo, NULL, &ft_routine, data + i))
			return ;
		i++;
	}
	if (pthread_create(&data->philo_d->t_death, NULL, &ft_is_dead, data))
		return ;
}
