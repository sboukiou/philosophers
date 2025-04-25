/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
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
	act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(UPURPLE"%ld %d is thinking\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
	ft_usleep(60);
}

void	eat(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(BGREEN"%ld %d is eating\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
	ft_usleep(philo->program->time_to_eat);
	philo->meal_count++;
	philo->last_meal_time = get_current_time_msec(philo->program);
}

void	snooze(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(BBLUE"%ld %d is sleeping\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
	ft_usleep(philo->program->time_to_sleep);
}

void	died(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(BRED"%ld %d died\n"RESET, timestamp, philo->id);
	if (philo->program)
		act_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	take_left_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time_msec(philo->program);
	act_mutex(&philo->left_fork->fork_mtx, LOCK);
	philo->left_fork->taken = true;
	act_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the left fork\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	take_right_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time_msec(philo->program);
	act_mutex(&philo->right_fork->fork_mtx, LOCK);
	philo->right_fork->taken = true;
	act_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the right fork\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
}
void	release_forks(t_philo *philo)
{
	act_mutex(&philo->left_fork->fork_mtx, UNLOCK);
	philo->left_fork->taken = false;
	act_mutex(&philo->right_fork->fork_mtx, UNLOCK);
	philo->right_fork->taken = false;
}
