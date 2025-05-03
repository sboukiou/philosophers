/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:57:16 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/01 18:11:45 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	init_program_locks(t_program *prog)
{
	int	count;

	prog->all_philos_full = false;
	prog->philos_ready = false;
	prog->philo_died = false;
	if (set_mutex(&prog->philos_ready_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->all_philos_full_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->philo_died_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->printf_mtx, INIT) != SUCCESS)
		return (FAIL);
	count = 0;
	while (count < prog->philo_count)
	{
		if (set_mutex(&prog->philos[count].meal_count_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count].fork_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count].taken_mtx, INIT) != SUCCESS)
			return (FAIL);
		count++;
	}
	return (SUCCESS);
}

static int	init_program_memory(t_program *prog)
{
	if (!prog)
	{
		print_error(NULL, "Program was not allocated properly !");
		return (FAIL);
	}
	prog->philos = (t_philo *)malloc(sizeof(t_philo) * prog->philo_count);
	if (!prog->philos)
	{
		print_error(prog, "Failed to allocate philosophers !");
		return (FAIL);
	}
	memset(prog->philos, '\0', sizeof(t_philo) * prog->philo_count);
	prog->forks = (t_fork *)malloc(sizeof(t_fork) * prog->philo_count);
	if (!prog->forks)
	{
		print_error(NULL, "Failed to allocate forks !");
		return (FAIL);
	}
	memset(prog->philos, '\0', sizeof(t_fork) * prog->philo_count);
	return (SUCCESS);
}

static int	init_program_philos_data(t_program *prog)
{
	int	count;
	int	checker;
	t_philo	*philo;

	count= 0;
	while (count< prog->philo_count)
	{
		philo = prog->philos + count;
		philo->id = count + 1;
		philo->program = prog;
		philo->meal_count = 0;
		philo->last_meal_time = 0;
		philo->left_fork = &prog->forks[count];
		philo->right_fork = &prog->forks[(count + 1) % prog->philo_count];
		checker = pthread_create(&philo->thread_id, NULL, philosopher, philo);
		if (checker != SUCCESS)
		{
			print_error(NULL, "Failed to create thread");
			return (FAIL);
		}
		count++;
	}
	return (SUCCESS);
}

int	init(t_program	*program)
{
	int	count;

	if (init_program_memory(program) != SUCCESS)
		return (FAIL);
	if (init_program_locks(program) != SUCCESS)
		return (print_info(NULL, "Failed to initialize program Locks"), FAIL);
	count = 0;
	while (count < program->philo_count)
	{
		program->forks[count].id = count + 1;
		program->forks[count].taken = false;
		count++;
	}
	if (init_program_philos_data(program) != SUCCESS)
		return (FAIL);
	set_bool(&program->philos_ready, true, &program->philos_ready_mtx);
	return (SUCCESS);
}
