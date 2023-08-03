/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:01:39 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/03 13:26:06 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	update_meal_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_mut);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_mut);
}

void	update_begin_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_mut);
	philo->last_meal_time = philo->data->begin_time;
	pthread_mutex_unlock(&philo->meal_time_mut);
}
