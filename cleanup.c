/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:52:13 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 14:10:54 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

static int	destroy_program_locks(t_program *prog)
{
	int	count;

	if (set_mutex(&prog->all_philos_full_mtx, DESTROY) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->philos_ready_mtx, DESTROY) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->philo_died_mtx, DESTROY) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->printf_mtx, DESTROY) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->end_of_simu_mtx, DESTROY) != SUCCESS)
		return (FAIL);
	count = 0;
	while (count < prog->philo_count)
	{
		if (set_mutex(&prog->philos[count].meal_count_mtx, DESTROY) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count].fork_mtx, DESTROY) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count].taken_mtx, DESTROY) != SUCCESS)
			return (FAIL);
		count++;
	}
	return (SUCCESS);
}

void	cleanup(t_program *program)
{
	if (!program)
		return ;
	if (destroy_program_locks(program) != SUCCESS)
		print_error(program, "Failed to destroy all the locks !! Leaving ...");
	print_info(program, "Freeing program resources");
	free(program->philos);
	free(program->forks);
	free(program);
}
