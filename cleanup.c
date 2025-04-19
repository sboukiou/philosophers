/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:52:13 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 09:55:11 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void	cleanup(t_program *program)
{
	if (!program)
		return ;
	print_info(program, "Cleaning up the program .");
	pthread_mutex_destroy(&program->philos_ready_mtx);
	pthread_mutex_destroy(&program->printf_mtx);
	free(program->philos);
	free(program);
	exit(0);

}
