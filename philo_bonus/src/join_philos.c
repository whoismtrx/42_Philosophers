/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:38:26 by orekabe           #+#    #+#             */
/*   Updated: 2022/07/17 20:22:44 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_kill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_d->n_philos)
	{
		kill(data->philo_d->pid[i], 9);
		i++;
	}
}

void	ft_join_philos(t_data *data)
{
	waitpid(-1, 0, 0);
	ft_kill(data);
}
