/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:16:50 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/27 21:50:24 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	update_last_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_time_mut);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_time_mut);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->state_mut);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->state_mut);
}

void	set_keep_checking(t_data *data, int value)
{
	pthread_mutex_lock(&data->keep_checking_mut);
	data->keep_checking = value;
	pthread_mutex_unlock(&data->keep_checking_mut);
}
