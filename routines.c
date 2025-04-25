/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:01 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*philo_init(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;

	philo = (t_philo *)arg;
	while (bool_getter(&philo->program->philos_ready, &philo->program->philos_ready_mtx) == false)
		;
	while (true)
	{
		if (bool_getter(&philo->program->philo_died, &philo->program->philo_died_mtx) == true)
			pthread_detach(pthread_self());
		if (bool_getter(&philo->left_fork->taken, &philo->left_fork->fork_taken_mtx) == false &&
			bool_getter(&philo->right_fork->taken, &philo->left_fork->fork_taken_mtx) == false &&
		is_priority(philo))
		{
			bool_setter(&philo->left_fork->taken, true, &philo->left_fork->fork_taken_mtx);
			bool_setter(&philo->right_fork->taken, true, &philo->left_fork->fork_taken_mtx);
			take_right_fork(philo);
			take_left_fork(philo);
			eat(philo);
			release_forks(philo);
			bool_setter(&philo->left_fork->taken, false, &philo->left_fork->fork_taken_mtx);
			bool_setter(&philo->right_fork->taken, false, &philo->left_fork->fork_taken_mtx);
		}
		else
	{
			snooze(philo);
			think(philo);
		}
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_program	*program;

	program = (t_program *)arg;
	if (!program)
		return (NULL);
	while (true)
	{
		for (int i = 0; i < program->philo_count; i++)
		{
			if (get_time_of_last_meal(program->philos[i]) >= program->time_to_die)
			{
				bool_setter(&program->philo_died, true,  &program->philo_died_mtx);
				died(program->philos + i);
				detach_all_threads(program);
				cleanup(program);
			}
		}
	}
	return (NULL);
}
