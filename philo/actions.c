/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:09 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 14:45:13 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	think(t_philo *philo)
{
	if (!philo || !philo->program)
		return ;
	set_status(philo, THINKING);
	write_status(philo, THINKING);
}

void	eat(t_philo *philo)
{
	int	meal_val;

	if (!philo || !philo->program)
		return ;
	set_status(philo, EATING);
	write_status(philo, EATING);
	philo->last_meal_time = get_current_time(philo->program);
	usnooze(philo->program, philo->program->time_to_eat);
	meal_val = get_number(&philo->meal_count, &philo->meal_count_mtx);
	set_number(&philo->meal_count, meal_val + 1, &philo->meal_count_mtx);
}

void	snooze(t_philo *philo)
{
	if (!philo || !philo->program)
		return ;
	set_status(philo, SLEEPING);
	write_status(philo, SLEEPING);
	usnooze(philo->program, philo->program->time_to_sleep);
}

void	died(t_philo *philo)
{
	if (!philo || !philo->program)
		return ;
	set_status(philo, DEAD);
	write_status(philo, DEAD);
	set_bool(&philo->program->end_of_simu, true, &philo->program->end_of_simu_mtx);
}

void	take_left_fork(t_philo *philo)
{
	if (!philo || !philo->program)
		return ;
	set_status(philo, TAKEN_FORK);
	set_mutex(&philo->left_fork->fork_mtx, LOCK);
	write_status(philo, TAKEN_FORK);
}

void	take_right_fork(t_philo *philo)
{
	if (!philo || !philo->program)
		return ;
	set_status(philo, TAKEN_FORK);
	set_mutex(&philo->right_fork->fork_mtx, LOCK);
	write_status(philo, TAKEN_FORK);
}
void	release_forks(t_philo *philo)
{
	set_status(philo, WAITING);
	set_mutex(&philo->left_fork->fork_mtx, UNLOCK);
	set_mutex(&philo->right_fork->fork_mtx, UNLOCK);
}
