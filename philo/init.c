/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:46:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:48:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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
	prog->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * prog->pc);
	if (!prog->forks)
	{
		printf(BRED"Failed to allocate philosophers [t_philo]\n"RESET);
		free(prog->philos);
		return (EXIT_FAILURE);
	}
	memset(prog->forks, '\0', sizeof(pthread_mutex_t) * prog->pc);
	return (EXIT_SUCCESS);
}

static int	init_prog_attributes(t_prog *prog)
{
	prog->end = false;
	prog->ready = false;
	if (set_mutex(&prog->ready_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->end_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->write_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->start_mtx, INIT) != SUCCESS)
		return (FAIL);
	return (EXIT_SUCCESS);
}

int	init(t_prog *prog)
{
	int		count;
	t_philo	*philo;

	if (init_memory(prog) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	count = 0;
	while (count < prog->pc)
	{
		philo = prog->philos + count;
		philo->mc = 0;
		philo->prog = prog;
		philo->id = count + 1;
		philo->right_fork = prog->forks + philo->id - 1;
		philo->left_fork = prog->forks + (philo->id % prog->pc);
		if (set_mutex(&philo->mc_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&philo->lmt_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count], INIT) != SUCCESS)
			return (FAIL);
		count++;
	}
	init_prog_attributes(prog);
	return (EXIT_SUCCESS);
}
