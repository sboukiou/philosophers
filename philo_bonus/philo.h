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
# include <semaphore.h> /* For sem_open() sem_close() sem_wait() ...
						   and semaphores utils */
# include <stdbool.h> /* For booleans */
# include <sys/time.h> /* For gettimeofday() */
# include <fcntl.h> /* For sem_open() flags O_CREAT && O_EXCEL */
# include <sys/wait.h> /* For waitpid() flags O_CREAT && O_EXCEL */

# define RESET "\033[0m"
# define BRED "\033[1;31m"
# define BACKGROUND_RED "\e[41m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define UPURPLE "\e[4;35m"

# define FAIL -1
# define SUCCESS 0
# define FULL 0
# define DEAD 127

# define FORK_SEM "/fork_sem"
# define WRITE_SEM "/write_sem"
# define READY_SEM "/ready_sem"
# define END_SEM "/end_sem"
# define MONITOR_START_SEM "/start_sem"
# define MC_SEM "/mc_sem"
# define LMT_SEM "/lmt_sem"
# define GLOB_END_SEM "/glob_end_lmt_sem"

typedef struct s_prog	t_prog;

typedef struct s_philo
{
	int				pc;
	int				id;
	pid_t			pid;
	sem_t			*forks;
	time_t			lmt;
	int				mc;
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
	sem_t			*forks;
	bool			ready;
	sem_t			*ready_sem;
	bool			end;
	sem_t			*end_sem;
	time_t			start;
	sem_t			*monitor_start_sem;
	sem_t			*write_sem;
	sem_t			*glob_end;
	pthread_t		mthread;
};


/* Desp + Tokenization */
int		ft_atoi(const char *nptr);
int		tokenize(t_prog *prog, int ac, char **av);

/* Time functions --> time.c */
int		ft_usleep(t_prog *prog, int time);
time_t	get_current_time(t_prog *prog);

/* Init function --> init.c */
int		init(t_prog *prog);

/* Monitor and philo routines --> routine.c / monitor.c */
void	*monitor(void *arg);
int	create_processes(t_prog *prog);

/* Philo routine utils utils.c */
void	single_philo(t_philo *philo);
void	take_fork(t_philo *philo);
bool	end(t_philo *philo);
bool	ended(t_philo *philo);

/* Philo actions --> actions.c */
int		write_status(const char *status, t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	snooze(t_philo *philo);
#endif /* PHILO_H */
