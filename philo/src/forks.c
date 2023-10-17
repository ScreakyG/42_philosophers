/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:15:32 by fgonzale          #+#    #+#             */
/*   Updated: 2023/10/17 20:16:21 by fgonzale         ###   ########.fr       */
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
	if (!take_left_fork(philo))
		return (0);
	if (!take_right_fork(philo))
		return (0);
	return (1);
}
