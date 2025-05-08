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

static bool	is_dead(t_philo *philo)
{
	time_t	current_time;
	time_t	last_meal_time;

	if (!philo)
		return (true);
	current_time = get_current_time(philo->program, MSEC);
	last_meal_time = philo->last_meal_time;
	if (current_time - last_meal_time > philo->program->time_to_die && get_status(philo) != EATING)
		return (true);
	return (false);
}

static bool	all_philos_are_full(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->philo_count)
	{
		if (philo_finished(prog->philos + i) == false)
			return (false);
		i++;
	}
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_program	*prog;
	int		i;

	if (arg == NULL)
		return (NULL);
	prog = (t_program *)arg;
	while (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == false)
	{
		i = 0;
		while (i < prog->philo_count && !get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx))
		{
			if (is_dead(&prog->philos[i]) == true && philo_finished(&prog->philos[i]) == false)
			{
				died(&prog->philos[i]);
				return (NULL);
			}
			i++;
		}
		if (all_philos_are_full(prog) == true)
			return (NULL);
	}
	set_bool(&prog->end_of_simu, true, &prog->end_of_simu_mtx);
	return (NULL);
}
