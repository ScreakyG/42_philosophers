/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:15:32 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/08 17:26:40 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
}

int	take_right_fork(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD)
		return (0);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, FORK);
	return (1);
}

int	take_left_fork(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD)
		return (0);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, FORK);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (philo->data->philo_nb == 1)
		return (one_philo_case(philo), 0);
	if (philo->id % 2 == 0)
	{
		if (take_right_fork(philo) != 1)
			return (0);
		if (take_left_fork(philo) != 1)
		{
			drop_right_fork(philo);
			return (0);
		}
	}
	else
	{
		if (take_left_fork(philo) != 1)
			return (0);
		if (take_right_fork(philo) != 1)
		{
			drop_left_fork(philo);
			return (0);
		}
	}
	return (1);
}
