/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:35:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/16 21:06:46 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo->a_repeat = 0;
	if (pthread_mutex_init(&philo->m_death, NULL))
		return ;
	philo->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->n_forks);
	if (!philo->m_forks)
		return ;
	while (i < philo->n_philos)
	{
		data[i].philo_d = philo;
		data[i].id = i + 1;
		data[i].death = 0;
		data[i].repeat = 0;
		data[i].state_time = 0;
		data[i].last_meal = 0;
		if (pthread_mutex_init(&philo->m_forks[i], NULL))
			return ;
		i++;
	}
}
