/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:00:09 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/17 15:39:45 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_philo_dead(t_philo *philo)
{
	if (get_time() - get_last_meal_time(philo) >= philo->data->time_to_die)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}

time_t	get_death_timer(t_data *data)
{
	time_t	death_timer;

	pthread_mutex_lock(&data->death_timer_mutex);
	death_timer = data->time_to_die;
	pthread_mutex_unlock(&data->death_timer_mutex);
	return (death_timer);
}

int	keep_checking(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->keep_checking_mut);
	result = data->keep_checking;
	pthread_mutex_unlock(&data->keep_checking_mut);
	return (result);
}

time_t	get_last_meal_time(t_philo *philo)
{
	time_t	last_meal_time;

	pthread_mutex_lock(&philo->meal_time_mut);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_time_mut);
	return (last_meal_time);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	philo_state;

	pthread_mutex_lock(&philo->state_mut);
	philo_state = philo->state;
	pthread_mutex_unlock(&philo->state_mut);
	return (philo_state);
}
