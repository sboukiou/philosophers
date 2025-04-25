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

void	detach_all_threads(t_program *program)
{
	int	iter;

	if (!program || !program->philos)
		return ;
	iter = 0;
	while (iter < program->philo_count)
	{
		pthread_detach(program->philos[iter].thread_id);
		iter++;
	}
}

void	cleanup(t_program *program)
{
	if (!program)
		return ;
	print_info(program, "Cleaning up the program .");
	pthread_mutex_destroy(&program->philos_ready_mtx);
	pthread_mutex_destroy(&program->printf_mtx);
	pthread_mutex_destroy(&program->philo_died_mtx);
	for (int i = 0; i < program->philo_count; i++)
	{
		act_mutex(&program->forks[i].fork_mtx, DESTROY);
		act_mutex(&program->forks[i].fork_taken_mtx, DESTROY);
	}
	free(program->philos);
	free(program->forks);
	free(program);
	exit(0);

}
