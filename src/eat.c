/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:56:44 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/20 20:36:39 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void drop_right_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->right_fork);
}

void drop_left_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
}

int take_right_fork(t_philo *philo)
{
    // if (philo_died == 1)
        //return (0);
    if (get_philo_state(philo) == DEAD)
        return (0);
    pthread_mutex_lock(philo->right_fork);
    print_message(philo, FORK);
    return (1);
}

int take_left_fork(t_philo *philo)
{
    //if (philo_died == 1)
        //return (0);
    if (get_philo_state(philo) == DEAD)
        return (0);
    pthread_mutex_lock(philo->left_fork);
    print_message(philo, FORK);
    return (1);    
}

int take_forks(t_philo *philo)
{
    //if (philo->data->philo_nb == 1)
        //faire quelque chose pour ce cas
    if (philo->id % 2 == 0)
    {
        if(!take_right_fork(philo))
            return (0);
        if(!take_left_fork(philo))
        {
            drop_right_fork(philo);
            return (0);
        }
    }
    else
    {
        if (!take_left_fork(philo))
            return (0);
        if (!take_right_fork(philo))
        {
            drop_left_fork(philo);
            return (0);
        }
    }
    return (1);
}

void    sleep_eat_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->sleep_eat_mut);
    ft_usleep(philo->data->time_to_eat, philo);
    pthread_mutex_unlock(&philo->sleep_eat_mut);
}

int    eat(t_philo *philo)
{
    if(!take_forks(philo))
        return (0);
    set_philo_state(philo, EATING);
    print_message(philo, EAT);
    update_last_eat(philo);
    sleep_eat_time(philo);
    //update_meal_eaten(philo);
    drop_left_fork(philo);
    drop_right_fork(philo);
    return (1);
}