/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/21 03:31:02 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(int argc)
{
	if (argc < 5)
		printf("NEED MORE ARGUMENTS\n");
	else if (argc > 6)
		printf("TOO MUCH ARGUMENTS\n");
}

void	*ft_routine()
{
	return (NULL);
}

void	ft_create_philo(t_philo *philo, pthread_t *th_philo)
{
	int	i;

	i = 0;
	while(i < philo->n_philo)
	{
		pthread_create(&th_philo[i], NULL, &ft_routine, NULL);
		printf("Create philo N %d\n", i + 1);
		i++;
	}
}

void	ft_join_philo(t_philo *philo, pthread_t *th_philo)
{
	int	i;

	i = 0;
	while(i < philo->n_philo)
	{
		pthread_join(th_philo[i], NULL);
		printf("join philo N %d\n", i + 1);
		i++;
	}
}

void	philos(t_philo *philo)
{
	pthread_t		th_philo[philo->n_philo];
	pthread_mutex_t	m_forks[philo->n_forks];
	ft_create_philo(philo, th_philo);
	ft_join_philo(philo, th_philo);
}

int	 main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			return (1);
		philos(&philo);
		return (0);
	}
	else
		ft_perror(argc);
	return (1);
}
