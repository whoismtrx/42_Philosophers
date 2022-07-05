/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:35:54 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/05 04:48:00 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_data(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data) * philo->n_philos);
	if (!data)
		return ;
	while (i < philo->n_philos)
	{
		data[i].philo_d = philo;
		data[i]id = i + 1;
		data[i]death = 0;
		data[i]repeat = 0;
		data[i]state_time = 0;
		data[i]last_meal = 0;
		i++;
	}
}
