/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/23 14:21:58 by sboukiou         ###   ########.fr       */
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
		if (philo->id % 2)
		{
			act_mutex(&philo->right_fork->fork_mtx, LOCK);

			act_mutex(&philo->program->printf_mtx, LOCK);
			printf(BBLUE"%d Picked the right fork\n"BBLUE, philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);

			act_mutex(&philo->left_fork->fork_mtx, LOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			printf(BBLUE"%d Picked the left fork\n"BBLUE, philo->id);
			printf(BGREEN"%d is eating\n"BGREEN, philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			act_mutex(&philo->right_fork->fork_mtx, UNLOCK);
			act_mutex(&philo->left_fork->fork_mtx, UNLOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			philo->last_meal_time = get_current_time_msec(philo->program);
			printf(BYELLOW"%d is sleeping\n"BYELLOW, philo->id);
			ft_usleep(philo->program->time_to_sleep);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			printf("%d is Thinking\n", philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			ft_usleep(60);
		}
		else
		{
			act_mutex(&philo->left_fork->fork_mtx, LOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			printf(BBLUE"%d Picked the left fork\n"BBLUE, philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			act_mutex(&philo->right_fork->fork_mtx, LOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			printf(BBLUE"%d Picked the right fork\n"BBLUE, philo->id);
			printf(BGREEN"%d is eating\n"BGREEN, philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			act_mutex(&philo->right_fork->fork_mtx, UNLOCK);
			act_mutex(&philo->left_fork->fork_mtx, UNLOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			philo->last_meal_time = get_current_time_msec(philo->program);
			printf(BYELLOW"%d is sleeping\n"BYELLOW, philo->id);
			ft_usleep(philo->program->time_to_sleep);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			act_mutex(&philo->program->printf_mtx, LOCK);
			printf("%d is Thinking\n", philo->id);
			act_mutex(&philo->program->printf_mtx, UNLOCK);
			ft_usleep(60);
			
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
				program->philo_died = true;
				print_dead(program, program->philos[i].id);
				cleanup(program);
				exit(0);
			}
		}
	}
	return (program);
}
