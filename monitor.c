/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:19:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 12:34:22 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
/**/
void	monitor(t_program *prog)
{
	int	thread_check;

	if (!prog)
		return ;
	thread_check = pthread_create(&prog->monitor, NULL, monitor_routine, prog);
	if (thread_check != SUCCESS)
	{
		print_error(prog, "Failed to create the monitor thread");
		return ;
	}
}

void	*monitor_routine(void *arg)
{
	t_program	*prog;

	if (arg == NULL)
		return (NULL);
	prog = (t_program *)arg;
	while (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == false)
	{
		for (int i = 0; i < prog->philo_count; i++)
		{
			if (get_current_time_msec(prog) - get_time_of_last_meal(prog->philos[i]) > prog->time_to_die)
			{
				print_info(prog, "A philosopher died");
				died(&prog->philos[i]);
				return (NULL);
				set_bool(&prog->philo_died, true, &prog->philo_died_mtx);
				set_bool(&prog->end_of_simu, true, &prog->end_of_simu_mtx);
			}
		}
	}
	set_bool(&prog->end_of_simu, true, &prog->end_of_simu_mtx);
	return (NULL);
}
