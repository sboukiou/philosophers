/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:45:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/11 23:54:53 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	set_mutex(fork, LOCK);
	if (end(philo))
	{
		set_mutex(fork, UNLOCK);
		return ;
	}
	write_status("has taken a fork", philo);
}

int	eat(t_philo *philo)
{
	int	mc;

	if (end(philo) == true)
	{
		set_mutex(philo->right_fork, UNLOCK);
		set_mutex(philo->left_fork, UNLOCK);
		return (EXIT_FAILURE);
	}
	write_status("is eating", philo);
	ft_usleep(philo->prog, philo->prog->tte);
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	mc = get_number(&philo->mc, &philo->mc_mtx);
	set_number(&philo->mc, mc + 1, &philo->mc_mtx);
	set_mutex(philo->left_fork, UNLOCK);
	set_mutex(philo->right_fork, UNLOCK);
	if (mc == philo->prog->mc)
		return (1);
	return (0);
}

void	snooze(t_philo *philo)
{
	write_status("is sleeping", philo);
	ft_usleep(philo->prog, philo->prog->tts);
}

void	think(t_philo *philo)
{
	write_status("is thinking", philo);
}
