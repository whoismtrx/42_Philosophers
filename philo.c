/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/18 06:10:06 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_data(t_philo *philo)
{
	if (philo->n_philo == 0 || philo->n_forks == 0
		|| philo->t_to_die == 0 || philo->t_to_eat == 0
		|| philo->t_to_sleep == 0)
		return (1);
	return (0);
}

void	ft_get_data(t_philo *philo, int argc, char **argv)
{
	philo->n_philo = ft_atoi(argv[1]);
	philo->n_forks = ft_atoi(argv[1]);
	philo->t_to_die = ft_atoi(argv[2]);
	philo->t_to_eat = ft_atoi(argv[3]);
	philo->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->n_t_eat = ft_atoi(argv[5]);
	else
		philo->n_t_eat = 0;
}

int	ft_check_error(t_philo *philo, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("INVALID ARGUMENTS\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_get_data(philo, argc, argv);
	if (ft_check_data(philo))
	{
		printf("INVALID ARGUMENTS\n");
		return (1);
	}
	return (0);
}

void	ft_choose(int argc)
{
	if (argc < 5)
		printf("NEED MORE ARGUMENTS\n");
	else if (argc > 6)
		printf("TOO MUCH ARGUMENTS\n");
}

int	 main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			return (1);
		return (0);
	}
	else
		ft_choose(argc);
	return (1);
}
