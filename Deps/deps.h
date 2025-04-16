
#ifndef DEPS_H
# define DEPS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
int	_isdigit(int c);
int	_atoi(const char *nptr);
size_t	_strlen(const char *str);
void	print_info(char *info);
void	print_error(char *error);

#endif
