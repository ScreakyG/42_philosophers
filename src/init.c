/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:06:45 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/20 20:37:12 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int malloc_data(t_data *data)
{
    data->philo_id = malloc(data->philo_nb * sizeof(pthread_t));
    if (!data->philo_id)
        return (free_exit(data), 0);
    data->forks = malloc(data->philo_nb * sizeof(pthread_mutex_t));
    if (!data->forks)
        return (free_exit(data), 0);
    data->philo_struct = malloc(data->philo_nb * sizeof(t_philo));
    if (!data->philo_struct)
        return (free_exit(data), 0);
    return (1);
}

int init_philos(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_nb)
    {
        data->philo_struct[i].data = data;
        data->philo_struct[i].id = i + 1;
        data->philo_struct[i].meals_eaten = 0;
        data->philo_struct[i].state = IDLE;
        pthread_mutex_init(&data->philo_struct[i].meal_time_mut, NULL);
        pthread_mutex_init(&data->philo_struct[i].state_mut, NULL);
        pthread_mutex_init(&data->philo_struct[i].sleep_eat_mut, NULL);
        update_last_eat(&data->philo_struct[i]);
    }
    return (1);
}

int init_data(int argc, char **argv, t_data *data)
{
    data->philo_nb = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->meal_must_eat = -1;
    if (argc == 6)
        data->meal_must_eat = ft_atoi(argv[5]);
    if (!malloc_data(data))
        return (0);
    data->keep_checking = 1;
    pthread_mutex_init(&data->write, NULL);
    pthread_mutex_init(&data->keep_checking_mut, NULL);
    pthread_mutex_init(&data->death_timer_mutex, NULL);
    return (1);   
}

int init_forks(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->philo_nb)
        pthread_mutex_init(&data->forks[i], NULL);
    i = 0;
    data->philo_struct[0].left_fork = &data->forks[0];
    data->philo_struct[0].right_fork = &data->forks[data->philo_nb - 1];
    while (++i < data->philo_nb)
    {
        data->philo_struct[i].left_fork = &data->forks[i];
        data->philo_struct[i].right_fork = &data->forks[i - 1];
    }
    return (1);
}

int init(int argc, char **argv, t_data *data)
{
    if (!init_data(argc, argv, data))
        return (0);
    if (!init_philos(data))
        return (free_exit(data), 0);
    if (!init_forks(data))
        return (free_exit(data), 0);
    return (1);
}