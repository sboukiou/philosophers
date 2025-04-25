
#ifndef DEPS_H
# define DEPS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#include "../types.h"
#include "../includes.h"
/* Stdlib functions */
int	_isdigit(int c);
int	_atoi(const char *nptr);
size_t	_strlen(const char *str);

#define RESET "\033[0m"
#define BRED "\033[1;31m"
#define BACKGROUND_RED "\e[41m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define UPURPLE "\e[4;35m"

/* Printers */
void	print_info(t_program *program, char *info);
void	print_error(t_program *program, char *error);

void	think(t_philo *philo);
void	eat(t_philo *philo);
void	snooze(t_philo *philo);
void	died(t_philo *philo);
void	take_right_fork(t_philo *philo);
void	take_left_fork(t_philo *philo);
void	release_forks(t_philo *philo);
#endif
