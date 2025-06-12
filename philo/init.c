/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:57:16 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 14:11:10 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	init_program_data(t_program *prog)
{
	prog->philos_ready = false;
	prog->end_of_simu = false;
	prog->philo_died = false;
	if (set_mutex(&prog->printf_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->philos_ready_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->number_of_meals_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->end_of_simu_mtx, INIT) != SUCCESS)
		return (FAIL);
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
	memset(prog->forks, '\0', sizeof(t_fork) * prog->philo_count);
	return (SUCCESS);
}

static int	init_philos(t_program *prog)
{
	int	count;
	t_philo	*philo;

	count= 0;
	while (count< prog->philo_count)
	{
		philo = prog->philos + count;
		philo->meal_count = 0;
		philo->program =  prog;
		philo->id = count + 1;
		philo->right_fork = prog->forks + philo->id - 1;
		philo->left_fork = prog->forks + (philo->id % prog->philo_count);
		if (set_mutex(&philo->meal_count_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&philo->status_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&philo->last_meal_time_mtx, INIT) != SUCCESS)
			return (FAIL);
		philo->status = WAITING;
		count++;
	}
	return (SUCCESS);
}

static int	init_forks(t_program *prog)
{
	int	iter;
	t_fork	*fork;

	iter = 0;
	if (!prog)
		return (FAIL);
	while (iter < prog->philo_count)
	{
		fork = &prog->forks[iter];
		fork->id = iter + 1;
		if (set_mutex(&fork->fork_mtx, INIT) != SUCCESS)
			return (FAIL);
		iter++;
	}
	return (SUCCESS);
}

int	init(t_program	*program)
{
	if (init_program_memory(program) != SUCCESS)
		return (FAIL);
	if (init_forks(program) != SUCCESS)
		return (print_info(NULL, "Failed to initialize forks"), FAIL);
	if (init_philos(program) != SUCCESS)
		return (print_error(NULL, "Failed to initialized philosophres"), FAIL);
	if (init_program_data(program) != SUCCESS)
		return (print_error(NULL, "Failed to initialized program data"), FAIL);
	return (SUCCESS);
}
