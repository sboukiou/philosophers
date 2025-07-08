/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:45:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:45:11 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


bool	ended(t_philo *philo)
{
	time_t	now;


	now = get_current_time(philo->prog);
	if (now - philo->lmt > philo->prog->ttd)
	{
		write_status(BRED"died", philo);
		exit(DEAD);
	}
	return (false);
}

int	write_status(const char *status, t_philo *philo)
{
	time_t	now;

	now = get_current_time(philo->prog);
	sem_wait(philo->prog->write_sem);
	printf("[%8lu] %d %s\n"RESET, now, philo->id, status);
	if (strcmp(status, BRED"died") != 0)
		sem_post(philo->prog->write_sem);
	return (0);
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	take_fork(philo);
	write_status(BGREEN"is eating", philo);
	philo->lmt =  get_current_time(philo->prog);
	ft_usleep(philo->prog, philo->prog->tte);
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
	ft_usleep(philo->prog, philo->prog->tts);
}

void	think(t_philo *philo)
{
	ended(philo);
	write_status(UPURPLE"is thinking", philo);
	ft_usleep(philo->prog, 1);
}
