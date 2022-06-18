/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:34:13 by orekabe           #+#    #+#             */
/*   Updated: 2022/06/18 06:08:51 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int			n_philo;
	int			n_forks;
	long long	t_to_die;
	long long	t_to_eat;
	long long	t_to_sleep;
	int			n_t_eat;
}				t_philo;

int	ft_atoi(char *str);
int	ft_isdigit(char c);

#endif