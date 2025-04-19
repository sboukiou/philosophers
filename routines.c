/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 10:16:13 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*philo_init(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;

	philo = (t_philo *)arg;
	print_info(philo->program, "Philo created");
	print_thinking(philo->program, philo->id, philo->program->start_time);
	return (NULL);
}
