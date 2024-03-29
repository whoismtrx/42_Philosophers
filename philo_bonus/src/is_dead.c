/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:32:18 by orekabe           #+#    #+#             */
/*   Updated: 2022/12/26 20:34:37 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_check(t_data *data)
{
	if (data->philo_d->a_repeat == data->philo_d->n_t_eat)
		exit (0);
	if (data->death >= data->philo_d->t_to_die)
	{
		sem_wait(data->philo_d->s_death);
		printf("%lld %d died\n", data->state_time, data->id);
		exit (0);
	}
}

void	*ft_is_dead(void *add)
{
	t_data		*data;
	int			i;

	i = 0;
	data = add;
	ft_mysleep(1);
	while (1)
	{
		sem_wait(data->philo_d->s_death);
		ft_get_state_time(data);
		data->death = data->state_time - data->last_meal;
		sem_post(data->philo_d->s_death);
		ft_check(data);
		if (data->repeat == data->philo_d->n_t_eat)
			data->philo_d->a_repeat++;
		if (i + 1 == data->philo_d->n_philos)
			i = -1;
		i++;
	}
	return (NULL);
}
