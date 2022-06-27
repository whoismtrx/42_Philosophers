/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:47:01 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/27 08:09:48 by orekabe          ###   ########.fr       */
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

void	ft_init_data(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo->life = 1;
	philo->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->n_forks);
	if (!philo->m_forks)
		return ;
	while(i < philo->n_philos)
	{
		data[i].philo_d = philo;
		data[i].id = i + 1;
		pthread_mutex_init(&philo->m_forks[i], NULL);
		i++;
	}
}

void	*ft_routine(void *add)
{
	t_data	*data;

	data = add;
	while (data->philo_d->life)
	{
		ft_is_dead(data);
		ft_taken_a_fork(data);
		ft_is_eating(data);
		ft_is_sleeping(data);
		ft_is_thinking(data);
	}
	return NULL;
}

void	ft_create_philos(t_data *data)
{
	int	i;

	i = 0;
	ft_get_start_time(data);
	while (i < data->philo_d->n_philos)
	{
		pthread_create(&data[i].th_philo, NULL, &ft_routine, data + i);
		i++;
	}
}

void	ft_join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_d->n_philos)
	{
		pthread_join(data[i].th_philo, NULL);
		i++;
	}
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
