/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:03:56 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/27 22:06:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->write);
	if (keep_checking(philo->data))
		printf("%ld %d %s\n", (get_time() - philo->data->begin_time), philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_help(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}

long	ft_atoi(char *str)
{
	int		i;
	long	signe;
	long	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (resultat * signe);
}

void	sim_start_delay(time_t start_time)
{
	while (get_time() < start_time)
		continue ;
}
