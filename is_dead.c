/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:32:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 08:09:20 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_dead(t_data *data)
{
	int	death;

	death = data->state_time - data->last_meal;
	printf("%d\n", death);
	if (death > data->philo_d->t_to_die)
	{
		data->philo_d->life = 0;
		printf("%lld philo %d is dead\n", data->state_time, data->id);
	}
}