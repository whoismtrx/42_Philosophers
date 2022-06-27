/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:53:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 04:53:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_sleeping(t_data *data)
{
	ft_get_state_time(data);
	printf("%lld philo %d is sleeping\n",data->state_time, data->id);
	usleep(data->philo_d->t_to_sleep * 1000);
}