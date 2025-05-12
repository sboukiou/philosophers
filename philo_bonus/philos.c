/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 14:14:03 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

bool	check_end(t_program *prog)
{
	if (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == true)
		return (true);
	return (false);
}

bool	philo_finished(t_philo *philo)
{
	int	meal_count;
	int	number_of_meals;

	meal_count = get_number(&philo->meal_count, &philo->meal_count_mtx);
	number_of_meals = get_number(&philo->program->number_of_meals, &philo->program->number_of_meals_mtx);
	if (number_of_meals == -1)
		return (false);
	if (meal_count >= number_of_meals)
		return (true);
	return (false);
}

static	void	wait_all_threads(t_program *prog)
{
	bool	val;

	val = get_bool(&prog->philos_ready, &prog->philos_ready_mtx);
	if (val == true)
		return ;
	while (val == false)
		val = get_bool(&prog->philos_ready, &prog->philos_ready_mtx);
}

void	*philosopher(void *args)
{
	t_philo	*philo;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	wait_all_threads(philo->program);
	philo->last_meal_time = get_current_time(philo->program);
	while (true)
	{
		if (philo->id % 2 == 0)
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
		if (philo_finished(philo) == true)
			return (NULL);
		if (check_end(philo->program) == true)
			return (NULL);
		snooze(philo);
		if (check_end(philo->program) == true)
			return (NULL);
		think(philo);
		if (check_end(philo->program) == true)
			return (NULL);
	}
	return (NULL);
}
