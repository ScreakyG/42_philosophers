/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:36:49 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/05 21:07:58 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->write, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->keep_checking_mut, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_timer_mutex, NULL) != 0)
		return (0);
	return (1);
}
