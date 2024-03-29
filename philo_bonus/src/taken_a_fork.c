/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 05:01:48 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 01:06:47 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_taken_a_fork(t_data *data)
{
	sem_wait(data->philo_d->s_forks);
	sem_wait(data->philo_d->s_death);
	ft_get_state_time(data);
	printf("%lld %d has taken a fork\n", data->state_time, data->id);
	sem_post(data->philo_d->s_death);
	sem_wait(data->philo_d->s_forks);
	sem_wait(data->philo_d->s_death);
	ft_get_state_time(data);
	printf("%lld %d has taken a fork\n", data->state_time, data->id);
	sem_post(data->philo_d->s_death);
}
