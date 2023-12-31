/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:43:29 by fgonzale          #+#    #+#             */
/*   Updated: 2023/08/03 13:30:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	update_begin_time(philo);
	sim_start_delay(philo->data->begin_time);
	update_last_eat(philo);
	if (philo->id % 2 == 0)
	{
		ft_think(philo, 0);
	}
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 1)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (!ft_sleep(philo))
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (!ft_think(philo, 1))
			break ;
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int	i;

	i = -1;
	data->begin_time = get_time() + (data->philo_nb * 2 * 10);
	while (++i < data->philo_nb)
	{
		if (pthread_create(&data->philo_id[i], NULL,
				&routine, &data->philo_struct[i]))
			return ;
	}
	if (pthread_create(&data->supervisor, NULL, &alive2, data))
		return ;
}

void	wait_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		if (data->philo_id[i] != 0 && pthread_join(data->philo_id[i], NULL))
			break ;
	}
	if (data->supervisor != 0)
		pthread_join(data->supervisor, NULL);
}
