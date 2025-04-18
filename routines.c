/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:04:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 18:50:28 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*philo_init(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->program->printf_mtx);
	philo = (t_philo *)arg;
	print_info("Philo created");
	printf("Philo id %d\n", philo->id);
	pthread_mutex_unlock(&philo->program->printf_mtx);
	return (NULL);
}
