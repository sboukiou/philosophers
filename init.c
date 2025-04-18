/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:57:16 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 19:55:06 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	init(t_program	*program)
{
	int	count;

	if (!program)
	{
		print_error("Program pointer given is NULL !");
		return (FAIL);
	}
	pthread_mutex_init(&program->printf_mtx, NULL);
	pthread_mutex_init(&program->philos_ready_mtx, NULL);
	program->philos_ready = false;
	program->philos = (t_philo *)malloc(sizeof(t_philo) * program->philo_count);

	if (!program->philos)
	{
		print_error("Failed to allocate philosophers!");
		return (FAIL);
	}
	count = 0;
	while (count < program->philo_count)
	{
		program->philos[count].id = count + 1;
		program->philos[count].program = program;
		pthread_create(&program->philos[count].thread_id, NULL, philo_init, program->philos + count);
		count++;
	}
	print_info("Done creating them");


	pthread_mutex_lock(&program->philos_ready_mtx);
	program->philos_ready = true;
	pthread_mutex_unlock(&program->philos_ready_mtx);
	return (SUCCESS);
}
