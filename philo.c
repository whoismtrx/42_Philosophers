/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/19 06:32:50 by orekabe          ###   ########.fr       */
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

void	ft_creat_philo(t_philo *philo)
{
	pthread_t		th_philo[philo->n_philo];
	pthread_mutex_t	m_forks[philo->n_forks];
	int				i;

	i = 1;
	while(i <= philo->n_philo)
	{
		pthread_create(&th_philo[i], NULL, &ft_routine, NULL);
		printf("Create philo N %d\n", i);
		i++;
	}
	i = 1;
	while(i <= philo->n_philo)
	{
		pthread_join(th_philo[i], NULL);
		printf("join philo N %d\n", i);
		i++;
	}
}

int	 main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			return (1);
		ft_creat_philo(&philo);
		return (0);
	}
	else
		ft_perror(argc);
	return (1);
}
