/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/12 09:39:48 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"
#include "../philo_bonus.h"


void	write_status(t_philo *philo, e_status status)
{
	time_t	timestamp;
	char	*str;

	if (status == THINKING)
		str = UPURPLE"is thinking"RESET;
	if (status == EATING)
		str = BGREEN"is eating"RESET;
	if (status == SLEEPING)
		str = BBLUE"is sleeping"RESET;
	if (status == TAKEN_FORK)
		str = BYELLOW"has taken a fork"RESET;
	if (status == DEAD)
		str = BRED"died"RESET;
	timestamp = get_current_time(philo->program);
	sem_wait(philo->program->write_sem);
	if (is_simulation_finished(philo->program) == true)
	{
		sem_post(philo->program->write_sem);
		return ;
	}

	printf("%ld %d %s\n", timestamp, philo->id, str);
	sem_post(philo->program->write_sem);
}

void	print_error(t_program *program, char *error)
{
	if (program)
		sem_wait(program->write_sem);
	write(STDERR_FILENO, BRED, _strlen(BRED));
	write(STDERR_FILENO, "[ERROR]: ", 10);
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, " \n", 3);
	write(STDERR_FILENO, RESET, _strlen(RESET));
	if (program)
		sem_post(program->write_sem);
}

void	print_info(t_program *program, char *info)
{
	if (program)
		sem_wait(program->write_sem);
	write(STDOUT_FILENO, BYELLOW, _strlen(BYELLOW));
	write(STDOUT_FILENO, "[INFO]: ", 9);
	write(STDOUT_FILENO, info, _strlen(info));
	write(STDOUT_FILENO, " \n", 3);
	write(STDOUT_FILENO, RESET, _strlen(RESET));
	if (program)
		sem_post(program->write_sem);
}
