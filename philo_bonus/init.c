/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:46:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/08 18:43:18 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	init_prog_attributes(t_prog *prog)
{
	prog->end = false;
	prog->ready = false;
	sem_unlink(READY_SEM);
	prog->ready_sem = sem_open(READY_SEM, O_CREAT | O_EXCL, 0644, 0);
	if (prog->ready_sem == SEM_FAILED)
		return (FAIL);
	sem_unlink(END_SEM);
	prog->end_sem = sem_open(END_SEM, O_CREAT | O_EXCL, 0644, 1);
	if (prog->end_sem == SEM_FAILED)
		return (FAIL);
	sem_unlink(WRITE_SEM);
	prog->write_sem = sem_open(WRITE_SEM, O_CREAT | O_EXCL, 0644, 1);
	if (prog->write_sem == SEM_FAILED)
		return (FAIL);
	sem_unlink(MONITOR_START_SEM);
	prog->monitor_start_sem = sem_open(MONITOR_START_SEM,
			O_CREAT | O_EXCL, 0644, 0);
	if (prog->monitor_start_sem == SEM_FAILED)
		return (FAIL);
	sem_unlink(GLOB_END_SEM);
	return (EXIT_SUCCESS);
}

static int	init_memory(t_prog *prog)
{
	if (!prog)
		return (EXIT_FAILURE);
	prog->philos = (t_philo *)malloc(sizeof(t_philo) * prog->pc);
	if (!prog->philos)
	{
		printf(BRED"Failed to allocate philosophers [t_philo]\n"RESET);
		return (EXIT_FAILURE);
	}
	memset(prog->philos, '\0', sizeof(t_philo) * prog->pc);
	sem_unlink(FORK_SEM);
	prog->forks = sem_open(FORK_SEM, O_CREAT | O_EXCL, 0644, prog->pc);
	if (prog->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * init - Initializes program data and philosophers
 */
int	init(t_prog *prog)
{
	int		count;
	t_philo	*philo;

	if (init_memory(prog) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_prog_attributes(prog))
		return (EXIT_FAILURE);
	count = 0;
	while (count < prog->pc)
	{
		philo = prog->philos + count;
		philo->mc = 0;
		philo->prog = prog;
		philo->id = count + 1;
		philo->forks = prog->forks;
		count++;
	}
	return (EXIT_SUCCESS);
}
