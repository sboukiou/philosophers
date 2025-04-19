/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 10:17:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"
#include "../philo.h"

#define RESET "\033[0m"
#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"

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

void	print_thinking(t_program *program, int id, long long timestamp)
{
	if (program)
		act_mutex(&program->printf_mtx, LOCK);
	printf(BGREEN"%lld %d is thinking\n"RESET, timestamp, id);
	if (program)
		act_mutex(&program->printf_mtx, UNLOCK);
}

void	print_eating(t_program *program, int id, long long timestamp)
{
	if (program)
		act_mutex(&program->printf_mtx, LOCK);
	write(STDOUT_FILENO, BBLUE, _strlen(BBLUE));
	printf("%lld %d is eating", timestamp, id);
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, RESET, _strlen(RESET));
	if (program)
		act_mutex(&program->printf_mtx, UNLOCK);
}
