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

