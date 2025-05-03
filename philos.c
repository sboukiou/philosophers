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

void	*philosopher(void *args)
{
	t_philo	*philo;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	while (get_bool(&philo->program->philos_ready, &philo->program->philos_ready_mtx) == false)
		;
	int	count = 0;
	while (count < philo->program->philo_count)
	{
		if (get_priority(philo))
		{
			if (philo->id % 2)
			{
				take_left_fork(philo);
				take_right_fork(philo);
			}
			else
			{
				take_right_fork(philo);
				take_left_fork(philo);
			}
			eat(philo);
			release_forks(philo);
		}
		snooze(philo);
		think(philo);
		count++;
	}

	return (NULL);
}
