/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:12:20 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/20 20:37:27 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    notify_philos(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_nb)
    {
        set_philo_state(&data->philo_struct[i], DEAD);
    }
}

void    *alive(void *data_ptr)
{
    t_data *data;
    int    i;

    i = -1;
    data = (t_data *)data_ptr;
    sim_start_delay(data->begin_time);
    while (i++ < data->philo_nb && keep_checking(data) == 1)
    {
        if (is_philo_dead(&data->philo_struct[i]))
        {
            print_message(&data->philo_struct[i], DIED);
            set_keep_checking(data, 0);
            notify_philos(data);
            break;
        }
        if (i == data->philo_nb - 1)
            i = -1;
        usleep(1000);
    }
    return (NULL);
}