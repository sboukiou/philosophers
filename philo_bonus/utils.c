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

void	single_philo(t_philo *philo)
{
	sem_wait(philo->forks);
	write_status(BYELLOW"has taken a fork", philo);
	ft_usleep(philo->prog->ttd);
	write_status(BRED"died", philo);
	exit(DEAD);
}

int	write_status(const char *status, t_philo *philo)
{
	time_t	now;

	now = get_current_time();
	sem_wait(philo->prog->write_sem);
	printf("[%8lu] %d %s\n"RESET, now - philo->prog->start, philo->id, status);
	if (strcmp(status, BRED"died") != 0)
		sem_post(philo->prog->write_sem);
	return (0);
}
