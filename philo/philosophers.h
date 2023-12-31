/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:13:36 by fgonzale          #+#    #+#             */
/*   Updated: 2023/11/06 03:37:09 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

# define DIED "died"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_time_mut;
	pthread_mutex_t	state_mut;
	pthread_mutex_t	sleep_eat_mut;
	pthread_mutex_t	meals_eaten_mut;
	int				id;
	int				meals_eaten;
	time_t			last_meal_time;
	t_state			state;
}	t_philo;

typedef struct s_data
{
	pthread_t		*philo_id;
	pthread_t		supervisor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	keep_checking_mut;
	pthread_mutex_t	death_timer_mutex;
	t_philo			*philo_struct;
	int				keep_checking;
	time_t			begin_time;
	int				philo_nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				meal_must_eat;
}	t_data;

/* CHECK ARGVS */

int			check_argvs(int argc, char **argv);

/* INIT */

int			init(int argc, char **argv, t_data *data);
int			init_data(int argc, char **argv, t_data *data);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
int			init_data_mutex(t_data *data);

/* SUPERVISOR */

void		*alive2(void *data_ptr);
int			keep_checking(t_data *data);
int			is_philo_dead(t_philo *philo);
int			end_conditions_reached(t_data *data);
int			end_supervisor(t_data *data);

/* EAT */

int			eat(t_philo *philo);
int			take_forks(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_right_fork(t_philo *philo);
void		drop_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);
void		sleep_eat_time(t_philo *philo);

/* SLEEP */

int			ft_sleep(t_philo *philo);
int			ft_usleep(time_t sleep_time, t_philo *philo);

/* THINK */

int			ft_think(t_philo *philo, int print);

/* THREADS */

void		start_threads(t_data *data);
void		*routine(void *data);
void		wait_threads(t_data *data);

/* ERROR */

void		free_exit(t_data *data);

/* UTILS */

long		ft_atoi(char *str);
void		print_help(void);
time_t		get_time(void);

void		print_message(t_philo *philo, char *str);

/* GETTERS */

t_state		get_philo_state(t_philo *philo);
time_t		get_last_meal_time(t_philo *philo);
time_t		get_death_timer(t_data *data);
int			get_philo_meals(t_philo *philo);

/* SETTERS */

void		set_philo_state(t_philo *philo, t_state state);
void		set_keep_checking(t_data *data, int value);
void		update_meal_eaten(t_philo *philo);
void		update_last_eat(t_philo *philo);
void		update_begin_time(t_philo *philo);

/* BAZAR */

void		notify_philos(t_data *data);
void		sim_start_delay(time_t start_time);
void		destroy_mutex(t_data *data);
void		one_philo_case(t_philo *philo);

#endif
