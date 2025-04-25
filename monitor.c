/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:19:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:35:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	monitor(t_program *program)
{
	int	check_thread_creation;

	if (program == NULL)
	{
		print_error(NULL, "Program not available");
		exit(0);
	}
	check_thread_creation = pthread_create(&program->monitor, NULL, monitor_routine, program);
	if (check_thread_creation != 0)
	{
		print_error(program, "Failed to create the monitor thread");
		exit(0);
	}
}
