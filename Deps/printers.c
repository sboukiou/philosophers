/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:23 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"
#include "../philo.h"


void	print_error(t_program *program, char *error)
{
	if (program)
		act_mutex(&program->printf_mtx, LOCK);
	write(STDERR_FILENO, BRED, _strlen(BRED));
	write(STDERR_FILENO, "[ERROR]: ", 10);
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, " \n", 3);
	write(STDERR_FILENO, RESET, _strlen(RESET));
	if (program)
		act_mutex(&program->printf_mtx, UNLOCK);
}

void	print_info(t_program *program, char *info)
{
	if (program)
		act_mutex(&program->printf_mtx, LOCK);
	write(STDOUT_FILENO, BYELLOW, _strlen(BYELLOW));
	write(STDOUT_FILENO, "[INFO]: ", 9);
	write(STDOUT_FILENO, info, _strlen(info));
	write(STDOUT_FILENO, " \n", 3);
	write(STDOUT_FILENO, RESET, _strlen(RESET));
	if (program)
		act_mutex(&program->printf_mtx, UNLOCK);
}

void	think(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(BGREEN"%ld %d is thinking\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	eat(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	act_mutex(&philo->program->printf_mtx, LOCK);
	timestamp = get_current_time_msec(philo->program);
	printf(BBLUE"%ld %d is eating\n"RESET, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
	ft_usleep(philo->program->time_to_eat);
}

void	died(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		act_mutex(&philo->program->printf_mtx, LOCK);
	printf(BRED"%lkj%d died\n"RESET, philo->id);
	if (philo->program)
		act_mutex(&philo->program->printf_mtx, UNLOCK);
	ft_usleep(philo->program->time_to_eat);
}

void	take_left_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time_msec(philo->program);
	act_mutex(&philo->left_fork->fork_mtx, LOCK);
	act_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the left fork\n"BBLUE, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	take_right_fork(t_philo *philo)
{
	time_t	timestamp;

	if (!philo || !philo->program)
		return ;
	timestamp = get_current_time_msec(philo->program);
	act_mutex(&philo->right_fork->fork_mtx, LOCK);
	act_mutex(&philo->program->printf_mtx, LOCK);
	printf(BBLUE"%ld %d has taken the right fork\n"BBLUE, timestamp, philo->id);
	act_mutex(&philo->program->printf_mtx, UNLOCK);
}
