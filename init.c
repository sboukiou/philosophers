/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:57:16 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/20 15:15:15 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	init(t_program	*program)
{
	int	count;

	if (!program)
	{
		print_error(NULL, "Program pointer given is NULL !");
		return (FAIL);
	}
	act_mutex(&program->printf_mtx, INIT);
	act_mutex(&program->philos_ready_mtx, INIT);
	program->philos_ready = false;
	program->philos = (t_philo *)malloc(sizeof(t_philo) * program->philo_count);
	if (!program->philos)
	{
		print_error(program, "Failed to allocate philosophers!");
		return (FAIL);
	}
	program->forks = (t_fork *)malloc(sizeof(t_fork) * program->philo_count);
	if (!program->forks)
	{
		print_error(NULL, "Failed to allocate forks!");
		return (FAIL);
	}
	count = 0;
	while (count < program->philo_count)
	{
		program->forks[count].id = count + 1;
		act_mutex(&program->forks[count].fork_mtx, INIT);
		bool_setter(&program->forks[count].taken, false, &program->forks[count].fork_mtx);
		count++;
	}
	count = 0;
	while (count < program->philo_count)
	{
		program->philos[count].id = count + 1;
		program->philos[count].program = program;
		program->philos[count].left_fork = &program->forks[(count + 1) % program->philo_count];
		program->philos[count].right_fork = &program->forks[count];
		pthread_create(&program->philos[count].thread_id, NULL,
		 philo_init, program->philos + count);
		count++;
	}


	bool_setter(&program->philos_ready , true, &program->philos_ready_mtx);
	program->start_time = get_current_time_msec(program);
	return (SUCCESS);
}
