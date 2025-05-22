/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:47:22 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/21 13:48:08 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

bool	are_philos_all_ready(t_program *prog)
{
	bool	val;

	sem_wait(prog->philos_all_ready_sem);
	val = prog->philos_all_ready;
	sem_post(prog->philos_all_ready_sem);
	return (val);
}

bool	is_simulation_finished(t_program *prog)
{
	bool	val;

	sem_wait(prog->end_of_simulation_sem);
	val = prog->end_of_simulation;
	sem_post(prog->end_of_simulation_sem);
	return (val);
}

void	stop_simulation(t_program *prog)
{
	sem_wait(prog->end_of_simulation_sem);
	prog->end_of_simulation = true;
	sem_post(prog->end_of_simulation_sem);
}


bool	has_philo_starved(t_philo *philo)
{
	time_t	last_meal_time;
	time_t current_time;

	current_time = get_current_time(philo->program);
	last_meal_time = philo->last_meal_time;
	if (current_time - last_meal_time > philo->program->time_to_die)
		return (true);
	return (false);
}
