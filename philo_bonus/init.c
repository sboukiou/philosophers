/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:37:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/20 20:43:01 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

#define LOCK 1
#define GLOBAL_SEM 0644

static time_t	get_current_time(t_program *prog)
{
	struct timeval	tv;
	struct timezone	tz;
	time_t	current_time;
	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		print_error(prog, "Failed to fetch current time (gettimeofday)");
		return (FAIL);
	}
		current_time = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
		return (current_time - prog->start_time);
}
void	initialize_program_data(t_program *prog)
{
	prog->start_time = get_current_time(prog);
	prog->philos_all_ready = false;
	prog->philo_died = false;
	prog->end_of_simulation = false;
	sem_open("philos_all_ready_sem", O_CREAT, GLOBAL_SEM, LOCK);
	sem_open("philo_died", O_CREAT, GLOBAL_SEM, LOCK);
	sem_open("end_of_simulation", O_CREAT, GLOBAL_SEM, LOCK);
}
