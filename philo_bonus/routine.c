/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:49:38 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:50:59 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	reopn_semaphores(t_philo *philo)
{
	philo->prog->ready_sem = sem_open(READY_SEM, 0);
	philo->prog->write_sem = sem_open(WRITE_SEM, 1);
	philo->prog->monitor_start_sem = sem_open(MONITOR_START_SEM, 0);
	philo->forks = sem_open(FORK_SEM, philo->prog->pc);
	philo->prog->glob_end = sem_open(READY_SEM, 0);
	if (philo->prog->ready_sem == SEM_FAILED)
		return (FAIL);
	if (philo->prog->write_sem == SEM_FAILED)
		return (FAIL);
	if (philo->prog->monitor_start_sem == SEM_FAILED)
		return (FAIL);
	if (philo->forks == SEM_FAILED)
		return (FAIL);
	if (philo->prog->glob_end == SEM_FAILED)
		return (FAIL);
	return (SUCCESS);
}

int	philo_routine(t_philo *philo)
{
	if (!philo)
		return (FAIL);
	reopn_semaphores(philo);
	sem_wait(philo->prog->ready_sem);
	if (philo->prog->pc == 1)
		single_philo(philo);
	if (philo->id % 2)
		usleep(400);
	while (true)
	{
		eat(philo);
		snooze(philo);
		think(philo);
	}
	exit(FULL);
	return (SUCCESS);
}


int	create_processes(t_prog *prog)
{
	int		i;
	pid_t	temp_pid;

	if (!prog)
		return (FAIL);
	i  = 0;
	prog->start = 0;
	prog->start = get_current_time(prog);
	while (i < prog->pc)
	{
		printf("Creating processes\n");
		temp_pid = fork();
		if (temp_pid == FAIL)
			return (FAIL);
		if (temp_pid == 0)
		{
			philo_routine(prog->philos + i);
			exit(SUCCESS);
		}
		prog->philos[i].pid = temp_pid;
		i++;
	}
	i  = 0;
	while (i++ < prog->pc)
		sem_post(prog->ready_sem);
	return (SUCCESS);
}
