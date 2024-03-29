/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:13:58 by orekabe           #+#    #+#             */
/*   Updated: 2022/12/26 19:49:46 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_is_eating(t_data *data)
{
	sem_wait(data->philo_d->s_death);
	ft_get_last_meal(data);
	ft_get_state_time(data);
	printf("%lld %d is eating\n", data->state_time, data->id);
	sem_post(data->philo_d->s_death);
	ft_mysleep(data->philo_d->t_to_eat);
	sem_post(data->philo_d->s_forks);
	sem_post(data->philo_d->s_forks);
}
