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


void	write_status(t_philo *philo, e_status status)
{
	time_t	timestamp;
	char	*str;

	if (status == THINKING)
		str = "is thinking";
	if (status == EATING)
		str = "is eating";
	if (status == SLEEPING)
		str = "is sleeping";
	if (status == TAKEN_FORK)
		str = "has taken a fork";
	if (status == DEAD)
		str = "died";
	timestamp = get_current_time(philo->program);
	set_mutex(&philo->program->printf_mtx, LOCK);
	if (get_bool(&philo->program->end_of_simu, &philo->program->end_of_simu_mtx) == true)
	{
		set_mutex(&philo->program->printf_mtx, UNLOCK);
		return ;
	}

	printf("%ld %d %s\n", timestamp, philo->id, str);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
}

void	print_error(t_program *program, char *error)
{
	if (program)
		set_mutex(&program->printf_mtx, LOCK);
	write(STDERR_FILENO, BRED, _strlen(BRED));
	write(STDERR_FILENO, "[ERROR]: ", 10);
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, " \n", 3);
	write(STDERR_FILENO, RESET, _strlen(RESET));
	if (program)
		set_mutex(&program->printf_mtx, UNLOCK);
}

void	print_info(t_program *program, char *info)
{
	if (program)
		set_mutex(&program->printf_mtx, LOCK);
	write(STDOUT_FILENO, BYELLOW, _strlen(BYELLOW));
	write(STDOUT_FILENO, "[INFO]: ", 9);
	write(STDOUT_FILENO, info, _strlen(info));
	write(STDOUT_FILENO, " \n", 3);
	write(STDOUT_FILENO, RESET, _strlen(RESET));
	if (program)
		set_mutex(&program->printf_mtx, UNLOCK);
}

