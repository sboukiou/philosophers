/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:37:50 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/21 13:50:42 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

#define LOCK 2
#define GLOBAL_SEM 0644

time_t	get_current_time(t_program *prog)
{
	struct timeval	tv;
	struct timezone	tz;
	time_t	current_time;
	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		printf(BRED"Failed to fetch current time (gettimeofday)\n"RESET);
		return (FAIL);
	}
	current_time = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (current_time - prog->start_time);
}
void	initialize_program_data(t_program *prog)
{
	prog->philos = (t_philo *)malloc(sizeof(t_philo) * prog->philo_count);
	if (!prog->philos)
	{
		printf(BRED" [Error]: Failed to allocate philos\n"RESET);
		return ;
	}
	prog->start_time = 0;
	prog->start_time = get_current_time(prog);
	prog->philos_all_ready = false;
	prog->philo_died = false;
	prog->end_of_simulation = false;
	sem_unlink("philos_all_ready_sem");
	sem_unlink("philo_died");
	sem_unlink("end_of_simulation");
	prog->philos_all_ready_sem = sem_open("philos_all_ready_sem", O_CREAT, GLOBAL_SEM, LOCK);
	prog->philo_died_sem = sem_open("philo_died", O_CREAT, GLOBAL_SEM, LOCK);
	prog->end_of_simulation_sem = sem_open("end_of_simulation", O_CREAT, GLOBAL_SEM, LOCK);
	if (!prog->philos_all_ready_sem || !prog->philo_died_sem || !prog->end_of_simulation_sem)
	{
		printf("Failed to open sem\n");
		exit(EXIT_FAILURE);
	}
}
