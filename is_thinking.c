/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:21:00 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 04:53:48 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_thinking(t_data *data)
{
	ft_get_state_time(data);
	printf("%lld philo %d is thinking\n",data->state_time, data->id);
}