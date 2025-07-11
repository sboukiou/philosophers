/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:45:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/08 18:40:20 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

bool	ended(t_philo *philo)
{
	time_t	now;

	now = get_current_time();
	if (now - philo->lmt > philo->prog->ttd)
	{
		write_status(BRED"died", philo);
		exit(DEAD);
	}
	return (false);
}

void	take_fork(t_philo *philo)
{
	sem_wait(philo->forks);
	ended(philo);
	write_status(BYELLOW"has taken a fork", philo);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	take_fork(philo);
	write_status(BGREEN"is eating", philo);
	philo->lmt = get_current_time();
	ft_usleep(philo->prog->tte, philo);
	sem_post(philo->forks);
	sem_post(philo->forks);
	philo->mc += 1;
	if (philo->mc == philo->prog->mc)
		exit(FULL);
}

void	snooze(t_philo *philo)
{
	ended(philo);
	write_status(BBLUE"is sleeping", philo);
	ft_usleep(philo->prog->tts, philo);
}

void	think(t_philo *philo)
{
	ended(philo);
	write_status(UPURPLE"is thinking", philo);
	ft_usleep(1, philo);
}
