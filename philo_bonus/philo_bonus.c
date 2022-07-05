/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:07:29 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/05 03:47:12 by orekabe          ###   ########.fr       */
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

void	philos(t_philo *philo, int id)
{
	t_data	*data;
	int		i;

	i = 0;
	philo->pid = (int *)malloc(sizeof(int) * philo->n_philos);
	if (!philo->pid)
		return ;
	ft_init_data(philo, data);
	ft_create_philos(data);
	ft_join_philos(data);
}

int main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_check_error(&philo, argc, argv))
			exit (1);
		philos(&philo);
		
		return (0);
	}
	else
		ft_perror(argc);
}