/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:57:31 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/03 13:25:32 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_think(t_philo *philo, int print)
{
	time_t	think_time;

	think_time = (get_death_timer(philo->data) - (get_time()
				- get_last_meal_time(philo)) - philo->data->time_to_eat) / 2;
	if (think_time < 0)
		think_time = 0;
	if (think_time > 600)
		think_time = 200;
	if (get_philo_state(philo) == DEAD)
		return (0);
	set_philo_state(philo, THINKING);
	if (print == 1)
		print_message(philo, THINK);
	ft_usleep(think_time, philo);
	return (1);
}
