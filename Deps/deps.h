
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
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"

/* Printers */
void	print_info(t_program *program, char *info);
void	print_error(t_program *program, char *error);
void	print_thinking(t_program *program, int id, long long timestamp);
void	print_eating(t_program *program, int id, long long timestamp);
void	print_dead(t_program *program, int id);

#endif
