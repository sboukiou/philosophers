/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/15 13:30:00 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> /* For printf */
# include <pthread.h> /* For posix threads | creation, monitor, join, mutexs, lock & unlock*/
# include <stdlib.h> /* For malloc, Free */
# include <unistd.h> /* For write, usleep */
# include <limits.h> /* INT_MIN & INT_MAX */

#include "./Deps/deps.h"

# define FAIL -1
# define SUCCESS 0

# define UNUSED 0
# define USED 1
enum	e_status
{
	THINKING,
	EATING,
	SLEEPING
};

typedef struct s_philosopher
{
	int		id;
	enum e_status	status;
	pthread_t	thread_id;
}	t_philosopher;

/*[DATA]: ./philo 8 200 200 150 [100]*/
typedef struct s_program
{
	int	philo_count;
	int	life_time;
	int	eating_period;
	int	sleep_period;
	int	meals_count;
	int	*forks;
}	t_program;
#endif
