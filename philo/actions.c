/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:45:04 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/12 01:20:50 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	set_mutex(fork, LOCK);
	if (end(philo) == true || death(philo) == true)
	{
		set_mutex(fork, UNLOCK);
		return (1);
	}
	write_status("has taken a fork", philo);
	return (0);
}

int	eat(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	if (take_fork(first, philo) || take_fork(second, philo))
		return (1);
	if (end(philo) == true || death(philo) == true)
	{
		set_mutex(philo->left_fork, UNLOCK);
		set_mutex(philo->right_fork, UNLOCK);
		return (1);
	}
	write_status("is eating", philo);
	ft_usleep(philo, philo->prog->tte);
	if (end(philo) || death(philo))
	{
		set_mutex(philo->left_fork, UNLOCK);
		set_mutex(philo->right_fork, UNLOCK);
		return (1);
	}
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	set_mutex(philo->left_fork, UNLOCK);
	set_mutex(philo->right_fork, UNLOCK);
	set_number(&philo->mc, get_number(&philo->mc,
			&philo->mc_mtx) + 1, &philo->mc_mtx);
	if (get_number(&philo->mc, &philo->mc_mtx) == philo->prog->mc)
		return (1);
	return (0);
}

int	snooze(t_philo *philo)
{
	if (end(philo) == true || death(philo) == true)
		return (1);
	write_status("is sleeping", philo);
	ft_usleep(philo, philo->prog->tts);
	if (end(philo) || death(philo))
		return (1);
	return (0);
}

int	think(t_philo *philo)
{
	if (end(philo) == true || death(philo) == true)
		return (1);
	write_status("is thinking", philo);
	if (end(philo) || death(philo))
		return (1);
	return (0);
}
