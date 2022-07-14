/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/14 00:17:21 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(int argc)
{
	if (argc < 5)
		write(2, "NEED MORE ARGUMENTS\n", 20);
	else if (argc > 6)
		write(2, "TOO MUCH ARGUMENTS\n", 19);
}

void	philos(t_philo *philo)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * philo->n_philos);
	if (!data)
		return ;
	ft_init_data(philo, data);
	ft_create_philos(data);
	ft_join_philos(data);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			return (1);
		philos(&philo);
		ft_mysleep(300);
		return (0);
	}
	else
		ft_perror(argc);
	return (1);
}
