/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:56:44 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/07 20:51:35 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	set_philo_state(philo, EATING);
	print_message(philo, EAT);
	update_last_eat(philo);
	sleep_eat_time(philo);
	update_meal_eaten(philo);
	drop_left_fork(philo);
	drop_right_fork(philo);
	return (1);
}
