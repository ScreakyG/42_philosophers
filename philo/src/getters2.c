/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:00:54 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/01 17:19:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	get_philo_meals(t_philo *philo)
{
	int	nb;

	pthread_mutex_lock(&philo->meals_eaten_mut);
	nb = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meals_eaten_mut);
	return (nb);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
