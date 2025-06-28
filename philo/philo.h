/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:43:41 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:54:45 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> /* For printf() */
# include <string.h> /* For memset() */
# include <stdlib.h> /* For malloc(), free() ... */
# include <unistd.h> /* For write() ?? */
# include <pthread.h> /* For pthread_create() and threads utils */
# include <stdbool.h> /* For booleans */
# include <sys/time.h> /* For gettimeofday() */

# define RESET "\033[0m"
# define BRED "\033[1;31m"
# define BACKGROUND_RED "\e[41m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define UPURPLE "\e[4;35m"

# define FAIL -1
# define SUCCESS 0

typedef struct s_prog	t_prog;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	time_t			lmt;
	pthread_mutex_t	lmt_mtx;
	int				pc;
	int				mc;
	int				id;
	pthread_mutex_t	mc_mtx;
	t_prog			*prog;
}	t_philo;

/**
 * struct holding all our program data
 */
struct s_prog
{
	int				ttd;
	int				tte;
	int				tts;
	int				mc;
	int				pc;
	t_philo			*philos;
	bool			ready;
	pthread_mutex_t	ready_mtx;
	bool			end;
	pthread_mutex_t	end_mtx;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mtx;
	time_t			start;
	pthread_mutex_t	start_mtx;
};

typedef enum e_mtx
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_mtx;

int		ft_atoi(const char *nptr);
int		tokenize(t_prog *prog, int ac, char **av);

/* Getters/Setters funcs --> gsetters.c */
int		set_mutex(pthread_mutex_t *mutex, t_mtx action);
bool	get_bool(bool *target, pthread_mutex_t *mtx);
void	set_bool(bool *target, bool value, pthread_mutex_t *mtx);
int		get_number(int *target, pthread_mutex_t *mtx);
void	set_number(int *target, int value, pthread_mutex_t *mtx);

/* Time functions --> time.c */
int		ft_usleep(t_prog *prog, int time);
time_t	get_current_time(t_prog *prog);
void	set_time(time_t *target, pthread_mutex_t *mtx, time_t val);
time_t	get_time(time_t *target, pthread_mutex_t *mtx);

/* Init function --> init.c */
int		init(t_prog *prog);

/* Monitor and philo routines --> routine.c / monitor.c */
int		simulation(t_prog *prog);
void	*monitor(void *arg);

/* Philo routine utils utils.c */
void	single_philo(t_philo *philo);
void	take_fork(pthread_mutex_t *fork, t_philo *philo);
void	assign_forks(t_philo *philo, pthread_mutex_t **first_fork,
			pthread_mutex_t **second_fork);
bool	end(t_philo *philo);

/* Philo actions --> actions.c */
int		write_status(const char *status, t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	snooze(t_philo *philo);
#endif /* PHILO_H */
