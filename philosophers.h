/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:13:36 by fgonzale          #+#    #+#             */
/*   Updated: 2023/07/22 12:16:48 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define DIED "died"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define WRONG_INPUT 0

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct s_data;

typedef struct s_philo
{
    struct s_data   *data;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_time_mut;
    pthread_mutex_t state_mut;
    pthread_mutex_t sleep_eat_mut;
    pthread_mutex_t meals_eaten_mut;
    int             id;
    int             meals_eaten;
    time_t             last_meal_time;
    t_state         state;
}   t_philo;

typedef struct s_data
{
    pthread_t   *philo_id;
    pthread_t   supervisor;
    pthread_mutex_t *forks;
    pthread_mutex_t write;
    pthread_mutex_t keep_checking_mut;
    pthread_mutex_t death_timer_mutex;
    t_philo     *philo_struct;
    int         keep_checking;
    time_t         begin_time;
    int         philo_nb;
    time_t         time_to_die;
    time_t         time_to_eat;
    time_t         time_to_sleep;
    int         meal_must_eat;
}   t_data;

/* CHECK ARGVS */

int     check_argvs(int argc, char **argv);

/* INIT */

int     init(int argc, char **argv, t_data *data);
int     init_data(int argc, char **argv, t_data *data);
int     init_philos(t_data *data);
int     init_forks(t_data *data);

/* SUPERVISOR */

void    *alive(void *data_ptr);

/* EAT */

int    eat(t_philo *philo);
int take_forks(t_philo *philo);
int take_left_fork(t_philo *philo);
int take_right_fork(t_philo *philo);
void drop_left_fork(t_philo *philo);
void drop_right_fork(t_philo *philo);
void    sleep_eat_time(t_philo *philo);


/* SLEEP */

int ft_sleep(t_philo *philo);
int ft_usleep(time_t sleep_time, t_philo *philo);

/* THINK */

int ft_think(t_philo *philo, int print);

/* THREADS */

void    start_threads(t_data *data);
void    *routine(void *data);
void    wait_threads(t_data *data);

/* ERROR */

void    free_exit(t_data *data);

/* UTILS */

int     ft_atoi(char *str);
void    print_help(void);
time_t     get_time(void);


void    print_message(t_philo *philo, char *str);

/* GETTERS */

t_state     get_philo_state(t_philo *philo);
time_t      get_last_meal_time(t_philo *philo);
time_t      get_death_timer(t_data *data);
int         get_philo_meals(t_philo *philo);

/* SETTERS */

void        set_philo_state(t_philo *philo, t_state state);
void        set_keep_checking(t_data *data, int value);
void        update_meal_eaten(t_philo *philo);
void        update_last_eat(t_philo *philo);

/* BAZAR */

int     keep_checking(t_data *data);
int     is_philo_dead(t_philo *philo);
void    *alive(void *data_ptr);

void    notify_philos(t_data *data);
void    sim_start_delay(time_t start_time);

void    *alive2(void *data_ptr);
int all_philos_full(t_data *data);
int end_conditions_reached(t_data *data);


#endif