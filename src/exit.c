/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:44 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/27 21:43:34 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->keep_checking_mut);
	pthread_mutex_destroy(&data->death_timer_mutex);
	while (++i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo_struct[i].meal_time_mut);
		pthread_mutex_destroy(&data->philo_struct[i].state_mut);
		pthread_mutex_destroy(&data->philo_struct[i].sleep_eat_mut);
		pthread_mutex_destroy(&data->philo_struct[i].meals_eaten_mut);
	}
}

void	free_exit(t_data *data)
{
	if (data)
	{
		if (data->philo_id)
			free(data->philo_id);
		if (data->forks)
			free(data->forks);
		if (data->philo_struct)
			free(data->philo_struct);
	}
}
