/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:46:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/21 13:46:53 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

static void	loop_checking(t_program *prog)
{
	t_philo	*philo;
	while (is_simulation_finished(prog) == false)
	{
		for (int i = 0; i < prog->philo_count; i++)
		{
			philo = &prog->philos[i];
			if (has_philo_starved(philo) == true)
				stop_simulation(prog);
		}
	}
}

static void	wait_for_philos(t_program *prog)
{
	while (are_philos_all_ready(prog) == false)
		;
	printf(BBLUE"loop ended all created and ready\n"RESET);
}

void	*monitor(void *arg)
{
	t_program *prog;

	prog = (t_program *)arg;
	wait_for_philos(prog);
	loop_checking(prog);
	return (NULL);
}

void	launch_monitor(t_program *prog)
{
	pthread_create(&prog->monitor, NULL, monitor, NULL);
}
