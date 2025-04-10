/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/07 14:37:52 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#include "./Deps/deps.h"

# define FAIL -1
# define SUCCESS 0

enum	e_status
{
	THINKING,
	EATING,
	SLEEPING
};

typedef struct s_philosopher
{
	int		left_fork;
	int		right_fork;
	int		id;
	enum e_status	status;
	pthread_t	thread;
}	t_philosopher;

typedef struct s_program_info
{
	int		number_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_each_must_eat;
	t_philosopher	*philos;
}	t_program_info;

t_program_info	*args_checker(int ac, char **av);
#endif
