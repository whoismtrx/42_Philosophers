/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:24:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/13 16:51:13 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mysleep(long long time)
{
	struct timeval	s_time;
	long long		c_time;
	long long		n_time;

	gettimeofday(&s_time, NULL);
	c_time = (s_time.tv_sec * 1000) + (s_time.tv_usec / 1000);
	n_time = c_time + time;
	while (c_time < n_time)
	{
		gettimeofday(&s_time, NULL);
		c_time = (s_time.tv_sec * 1000) + (s_time.tv_usec / 1000);
		usleep(50);
	}
}

