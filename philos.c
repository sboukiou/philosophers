/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 13:45:14 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

/*static bool	check_end(t_program *prog)*/
/*{*/
/*	if (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == true)*/
/*		return (true);*/
/*	return (false);*/
/*}*/

static	void	wait_all_threads(t_program *prog)
{
	bool	val;

	val = get_bool(&prog->philos_ready, &prog->philos_ready_mtx);
	if (val == true)
		return ;
	while (val == false)
		val = get_bool(&prog->philos_ready, &prog->philos_ready_mtx);
}

void	*philosopher(void *args)
{
	t_philo	*philo;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	wait_all_threads(philo->program);
	print_info(philo->program, "After all threads are ready");
	return (NULL);
}
