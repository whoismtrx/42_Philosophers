/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:07:29 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 21:58:30 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_perror(int argc)
{
	if (argc < 5)
		printf("NEED MORE ARGUMENTS\n");
	else if (argc > 6)
		printf("TOO MUCH ARGUMENTS\n");
}

void	ft_free(t_data *data)
{
	sem_close(data->philo_d->s_forks);
	sem_close(data->philo_d->s_death);
	sem_unlink("sem_forks");
	sem_unlink("sem_death");
	free(data->philo_d->pid);
	free(data);
}

void	philos(t_philo *philo)
{
	t_data	*data;

	philo->pid = (int *)malloc(sizeof(int) * philo->n_philos);
	if (!philo->pid)
		return ;
	data = (t_data *)malloc(sizeof(t_data) * philo->n_philos);
	if (!data)
		return ;
	ft_init_data(philo, data);
	ft_create_philos(data, philo);
	ft_join_philos(data);
	ft_free(data);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			exit (1);
		philos(&philo);
		exit (0);
	}
	else
		ft_perror(argc);
	exit (1);
}
