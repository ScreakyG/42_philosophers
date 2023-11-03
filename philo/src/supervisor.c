/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:12:20 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/03 15:40:31 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	notify_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		set_philo_state(&data->philo_struct[i], DEAD);
	}
}

void	*alive2(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	sim_start_delay(data->begin_time);
	while (keep_checking(data) == 1)
	{
		if (end_conditions_reached(data) == 1)
			break ;
		usleep(1000);
	}
	return (NULL);
}

int	end_conditions_reached(t_data *data)
{
	int		i;
	bool	philo_ate_enough;

	philo_ate_enough = true;
	i = -1;
	while (++i < data->philo_nb)
	{
		if (is_philo_dead(&data->philo_struct[i]))
		{
			print_message(&data->philo_struct[i], DIED);
			set_keep_checking(data, 0);
			notify_philos(data);
			return (1);
		}
		if (data->meal_must_eat != -1)
		{
			if (get_philo_meals(&data->philo_struct[i]) < data->meal_must_eat)
				philo_ate_enough = false;
		}
	}
	if (data->meal_must_eat != -1 && philo_ate_enough == true)
		end_supervisor(data);
	return (0);
}

int	end_supervisor(t_data *data)
{
	set_keep_checking(data, 0);
	notify_philos(data);
	return (1);
}
