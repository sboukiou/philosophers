
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

/* Printers */
void	print_info(t_program *program, char *info);
void	print_error(t_program *program, char *error);
void	print_thinking(t_program *program, int id, long long timestamp);
void	print_eating(t_program *program, int id, long long timestamp);

#endif
