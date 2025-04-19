/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 09:54:29 by sboukiou         ###   ########.fr       */
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
long long	get_actual_time_msec(t_program *program);

/* Parsing functions */
t_program	*parser(int ac, char **av);

/* Initers */
int	init(t_program	*program);
void	*philo_init(void *arg);

/* Cleanup functions */
void	cleanup(t_program *program);

/* Routines */
void	*philo_init(void *arg);

/* Getters & Setters */
void	act_mutex(pthread_mutex_t *mutex, t_mtx action);
bool	bool_getter(bool *target, pthread_mutex_t *mtx);
void	bool_setter(bool *target, bool value, pthread_mutex_t *mtx);

#endif
