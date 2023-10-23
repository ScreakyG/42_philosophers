/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:50:42 by fgonzale          #+#    #+#             */
/*   Updated: 2023/10/23 02:07:51 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	sleep_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->sleep_eat_mut);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(&philo->sleep_eat_mut);
}

int	ft_usleep(time_t sleep_time, t_philo *philo)
{
	time_t	wake;

	wake = get_time() + sleep_time;
	while (get_time() < wake)
	{
		if (get_philo_state(philo) == DEAD)
			break ;
		usleep(100);
	}
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (get_philo_state(philo) == DEAD)
		return (0);
	set_philo_state(philo, SLEEPING);
	print_message(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep, philo);
	return (1);
}
