/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:01:30 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 13:42:07 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	start_philos(t_program *prog)
{
	int	i;
	int	thread_cr;
	t_philo	*philo;

	i = 0;
	while (i < prog->philo_count)
	{
		philo = &prog->philos[i];
		philo->last_meal_time = prog->start_time + 1;
		thread_cr = pthread_create(&philo->thread_id, NULL, philosopher, prog->philos + i);
		if (thread_cr != SUCCESS)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	start_dinner(t_program *prog)
{
	if (!prog)
		return (FAIL);
	prog->start_time = get_current_time(prog, MSEC);
	start_philos(prog);
	set_bool(&prog->philos_ready, true, &prog->philos_ready_mtx);
	return (SUCCESS);
}
