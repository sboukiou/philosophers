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
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	set_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time(philo->program, MSEC);
	printf(UPURPLE"%ld %d is thinking\n"RESET, timestamp, philo->id);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
	usnooze(philo->program, 60);
}

void	eat(t_philo *philo)
{
	time_t	timestamp;
	int	meal_val;

	if (!philo || !philo->program)
		return ;
	set_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time(philo->program, MSEC);
	printf(BGREEN"%ld %d is eating\n"RESET, timestamp, philo->id);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
	usnooze(philo->program, philo->program->time_to_eat);
	meal_val = get_number(&philo->meal_count, &philo->meal_count_mtx);
	set_number(&philo->meal_count, meal_val + 1, &philo->meal_count_mtx);
	philo->last_meal_time = get_current_time(philo->program, MSEC);
}

void	snooze(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	set_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time(philo->program, MSEC);
	printf(BBLUE"%ld %d is sleeping\n"RESET, timestamp, philo->id);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
	usnooze(philo->program, philo->program->time_to_sleep);
}

void	died(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		set_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time(philo->program, MSEC);
	printf(BRED"%ld %d died\n"RESET, timestamp, philo->id);
	if (philo->program)
		set_mutex(&philo->program->printf_mtx, UNLOCK);
	set_bool(&philo->program->end_of_simu, true, &philo->program->end_of_simu_mtx);
}

void	take_left_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time(philo->program, MSEC);
	set_mutex(&philo->left_fork->fork_mtx, LOCK);
	philo->left_fork->taken = true;
	set_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the left fork\n"RESET, timestamp, philo->id);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	take_right_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time(philo->program, MSEC);
	set_mutex(&philo->right_fork->fork_mtx, LOCK);
	philo->right_fork->taken = true;
	set_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the right fork\n"RESET, timestamp, philo->id);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
}
void	release_forks(t_philo *philo)
{
	set_mutex(&philo->left_fork->fork_mtx, UNLOCK);
	philo->left_fork->taken = false;
	set_mutex(&philo->right_fork->fork_mtx, UNLOCK);
	philo->right_fork->taken = false;
}
