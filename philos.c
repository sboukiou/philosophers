/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:01 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*philosopher(void *args)
{
	t_philo	*philo;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	while (get_bool(&philo->program->philos_ready, &philo->program->philos_ready_mtx) == false)
		;
	print_info(philo->program, "Philo created ! Thinking ...");
	return (NULL);
}
