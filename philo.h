/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:05 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> /* For printf */
# include <pthread.h> /* For posix threads | creation, monitor, join, mutexs, lock & unlock*/
# include <stdlib.h> /* For malloc, Free */
# include <stdbool.h> /* For true, false */
# include <unistd.h> /* For write, usleep */
# include <limits.h> /* INT_MIN & INT_MAX */
#include <sys/time.h> /* For gettimeofday & settimeofday */

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

typedef struct s_philo t_philo;

/*[DATA]: ./philo 8 200 200 150 [100]*/
typedef struct s_program
{
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	t_philo	*philos;
	bool	philos_ready;
	pthread_mutex_t	philos_ready_mtx;
	pthread_mutex_t	printf_mtx;
}	t_program;

struct s_philo
{
	int		id;
	enum e_status	status;
	pthread_t	thread_id;
	t_program	*program;
};


/* Prototyeps for time functions */
int	ft_usleep(int time);

/* Parsing functions */
t_program	*parser(int ac, char **av);

/* Initers */
int	init(t_program	*program);
void	*philo_init(void *arg);

/* Cleanup functions */
void	cleanup(t_program *program);

/* Routines */
void	*philo_init(void *arg);

#endif
