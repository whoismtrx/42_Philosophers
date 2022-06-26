/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:53:46 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/26 03:32:39 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_sleeping(t_data *data)
{
	printf("%d is sleeping\n", data->id);
	usleep(data->philo_d->t_to_sleep * 1000);
}