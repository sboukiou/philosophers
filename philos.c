/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/01 18:23:02 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static bool	check_end(t_program *prog)
{
	if (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == true)
		return (true);
	return (false);
}

void	*philosopher(void *args)
{
	t_philo	*philo;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	while (get_bool(&philo->program->philos_ready, &philo->program->philos_ready_mtx) == false) ;
	if (check_end(philo->program) == true)
		return (NULL);
	while (true)
	{
		if (check_end(philo->program) == true)
			return (NULL);
		if (get_priority(philo) == true)
		{
			if (philo->id % 2 == 0)
			{
				if (check_end(philo->program) == true)
					return (NULL);
				take_left_fork(philo);
				if (check_end(philo->program) == true)
					return (NULL);
				take_right_fork(philo);
			}
			else
		{
				if (check_end(philo->program) == true)
					return (NULL);
				take_right_fork(philo);
				if (check_end(philo->program) == true)
					return (NULL);
				take_left_fork(philo);
			}
			if (check_end(philo->program) == true)
				return (NULL);
			eat(philo);
			if (check_end(philo->program) == true)
				return (NULL);
			release_forks(philo);
		}
		if (check_end(philo->program) == true)
			return (NULL);
		snooze(philo);
		think(philo);
		if (check_end(philo->program) == true)
			return (NULL);
	}
	return (NULL);
}
