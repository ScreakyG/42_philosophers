/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:57:31 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/08 17:31:42 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_think(t_philo *philo, int print)
{
	time_t	think_time;

	if (philo->data->philo_nb % 2
		&& (philo->data->time_to_sleep <= philo->data->time_to_eat))
		think_time = (philo->data->time_to_eat
				- philo->data->time_to_sleep) + 1;
	else
		think_time = 0;
	if (think_time == 0 && print == 0)
		think_time = 1;
	if (get_philo_state(philo) == DEAD)
		return (0);
	set_philo_state(philo, THINKING);
	if (print == 1)
		print_message(philo, THINK);
	ft_usleep(think_time, philo);
	return (1);
}
