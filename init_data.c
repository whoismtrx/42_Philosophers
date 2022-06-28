/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:35:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/28 05:44:33 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo->life = 1;
	pthread_mutex_init(&philo->m_death, NULL);
	philo->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->n_forks);
	if (!philo->m_forks)
		return ;
	while (i < philo->n_philos)
	{
		data[i].philo_d = philo;
		data[i].id = i + 1;
		pthread_mutex_init(&philo->m_forks[i], NULL);
		i++;
	}
}
