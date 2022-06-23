/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/23 05:34:25 by orekabe          ###   ########.fr       */
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

void	ft_init(t_philo *philo)
{
	pthread_t		th_philos[philo->n_philos];
	pthread_mutex_t	m_forks[philo->n_forks];

	philo->th_philos = th_philos;
	philo->m_forks = m_forks;
}

void	left_fork(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->m_forks[i + 1]);
	printf("philo %d take a left fork", i + 1);
	pthread_mutex_unlock(&philo->m_forks[i + 1]);
}

void	right_fork(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->m_forks[i]);
	printf("philo %d take a right fork", i + 1);
	pthread_mutex_unlock(&philo->m_forks[i]);
}

void	*ft_routine(void *add)
{
	t_philo	*philo;
	int		i;

	add = philo;
	i = 0;
	while (1)
	{
		if (i % 2 == 0)
		{
			left_fork(philo, i);
			right_fork(philo, i);
		}
		else
		{
			right_fork(philo, i);
			left_fork(philo, i);
		}
	}
	
	
	return (NULL);
}

void	ft_create_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->n_philos)
	{
		pthread_create(&philo->th_philos[i], NULL, &ft_routine, philo);
		// printf("Create philo N %d\n", i + 1);
		i++;
	}
}

void	ft_join_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->n_philos)
	{
		pthread_join(philo->th_philos[i], NULL);
		// printf("join philo N %d\n", i + 1);
		i++;
	}
}

void	philos(t_philo *philo)
{
	ft_init(philo);
	ft_create_philo(philo);
	ft_join_philo(philo);
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
