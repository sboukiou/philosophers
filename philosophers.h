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

# define FAIL -1
# define SUCCESS 0

typedef struct s_philo_data
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_each_must_eat;
	pthread_t	*philosophers;
}	t_philo_data;

typedef struct s_philosopher
{
	int	left_fork;
	int	right_fork;
}	t_philosopher;

t_philo_data	*args_checker(int ac, char **av);
#endif
