/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/12 11:09:35 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "./Deps/deps.h"
#include "./types.h"
#include "./includes.h"



/* Prototyeps for time functions */
int	usnooze(t_program *prog, int time);
time_t	get_current_time(t_program *prog);

/* Parsing functions */
t_program	*parser(int ac, char **av);

/* Initers */
int	init(t_program	*program);
void	*philo_init(void *arg);
int	start_dinner(t_program *prog);

/* Monitoring */
void	*monitor_routine(void *prog);
void	monitor(t_program *prog);

/* Cleanup functions */
void	cleanup(t_program *program);
void	detach_all_threads(t_program *program);

/* Routines */
void	*philosopher(void *args);
bool	check_end(t_program *prog);
bool	philo_finished(t_philo *philo);

/* Getters & Setters */
int	set_mutex(pthread_mutex_t *mutex, t_mtx action);
bool	get_bool(bool *target, pthread_mutex_t *mtx);
void	set_bool(bool *target, bool value, pthread_mutex_t *mtx);
int	get_number(int *target, pthread_mutex_t *mtx);
void	set_number(int *target, int value, pthread_mutex_t *mtx);
bool	get_priority(t_philo *philo);
bool	get_forks_available(t_philo *philo);
void	set_status(t_philo *philo, e_status status);
e_status	get_status(t_philo *philo);

#endif
