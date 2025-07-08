/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:53:13 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:53:42 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "deps.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->forks);
	ended(philo);
	write_status(BYELLOW"has taken a fork", philo);
}

void	single_philo(t_philo *philo)
{
	sem_wait(philo->forks);
	write_status(BYELLOW"has taken a fork", philo);
	ft_usleep(philo->prog, philo->prog->ttd);
	write_status(BRED"died", philo);

	exit(DEAD);
}
