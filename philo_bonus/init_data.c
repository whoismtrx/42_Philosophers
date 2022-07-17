/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:35:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 02:38:12 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sema(t_philo *philo)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_death");
	philo->s_forks = sem_open("sem_forks", O_CREAT, 0, philo->n_forks);
	if (philo->s_forks == SEM_FAILED)
	{
		write(2, "Failed to open semaphore for sem_forks\n", 38);
		exit (1);
	}
	philo->s_death = sem_open("sem_death", O_CREAT, 0, 1);
	if (philo->s_death == SEM_FAILED)
	{
		write(2, "Failed to open semaphore for sem_death\n", 38);
		exit (1);
	}
}

void	ft_init_data(t_philo *philo, t_data *data)
{
	int	i;

	init_sema(philo);
	i = 0;
	while (i < philo->n_philos)
	{
		data[i].philo_d = philo;
		data[i].id = i + 1;
		data[i].death = 0;
		data[i].repeat = 0;
		data[i].state_time = 0;
		data[i].last_meal = 0;
		i++;
	}
}
