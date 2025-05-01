/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:49 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "./Deps/deps.h"
#include "./types.h"
#include "./includes.h"

# define FAIL -1
# define SUCCESS 0

# define UNUSED 0
# define USED 1

# define THINKING_TIME 80

/* Prototyeps for time functions */
int	ft_usleep(int time);
time_t	get_current_time_msec(t_program *program);
time_t	get_time_of_last_meal(t_philo philo);

/* Parsing functions */
t_program	*parser(int ac, char **av);

/* Initers */
int	init(t_program	*program);
void	*philo_init(void *arg);

/* Monitoring */
void	*monitor_routine(void *prog);

/* Cleanup functions */
void	cleanup(t_program *program);
void	detach_all_threads(t_program *program);

/* Routines */
void	*philosopher(void *args);

/* Getters & Setters */
int	set_mutex(pthread_mutex_t *mutex, t_mtx action);
bool	get_bool(bool *target, pthread_mutex_t *mtx);
void	set_bool(bool *target, bool value, pthread_mutex_t *mtx);
int	get_number(int *target, pthread_mutex_t *mtx);
void	set_number(int *target, int value, pthread_mutex_t *mtx);
bool	get_priority(t_philo *philo);
bool get_all_eaten(t_program *program);

#endif
