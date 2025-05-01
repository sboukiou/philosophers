/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:47:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 14:08:46 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "./includes.h"

enum	e_status
{
	THINKING,
	EATING,
	SLEEPING
};

typedef struct s_philo t_philo;

typedef struct s_fork
{
	int 		id;
	pthread_mutex_t	fork_mtx;
	pthread_mutex_t	taken_mtx;
	bool		taken;
}	t_fork;

/*[DATA]: ./philo 8 200 200 150 [100]*/
typedef struct s_program
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	time_t	start_time;
	t_philo	*philos;
	bool	philos_ready;
	t_fork		*forks;
	bool		philo_died;
	bool		all_philos_full;
	pthread_t	monitor;
	pthread_mutex_t	philos_ready_mtx;
	pthread_mutex_t	printf_mtx;
	pthread_mutex_t	philo_died_mtx;
	pthread_mutex_t	all_philos_full_mtx;
}	t_program;

struct s_philo
{
	int		id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	pthread_t	thread_id;
	t_program	*program;
	time_t		last_meal_time;
	int		meal_count;
	pthread_mutex_t	meal_count_mtx;
};

typedef	enum e_mtx
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_mtx;

#endif
