/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:44 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/22 12:53:55 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    free_exit(t_data *data)
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
