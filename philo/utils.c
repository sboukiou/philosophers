/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:53:13 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/12 01:13:47 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	write_status(const char *status, t_philo *philo)
{
	time_t	now;

	now = get_current_time(philo->prog);
	set_mutex(&philo->prog->write_mtx, LOCK);
	if (end(philo))
	{
		set_mutex(&philo->prog->write_mtx, UNLOCK);
		return (0);
	}
	printf("[%8lu] %d %s\n", now, philo->id, status);
	set_mutex(&philo->prog->write_mtx, UNLOCK);
	return (0);
}

void	assign_forks(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}

void	single_philo(t_philo *philo)
{
	set_mutex(philo->left_fork, LOCK);
	write_status("has taken a fork", philo);
	set_mutex(philo->left_fork, UNLOCK);
	ft_usleep(philo, philo->prog->ttd);
	write_status("died", philo);
	return ;
}

bool	end(t_philo *philo)
{
	if (!philo)
		return (true);
	if (get_bool(&philo->prog->end, &philo->prog->end_mtx) == true)
		return (true);
	return (false);
}

bool	death(t_philo *philo)
{
	time_t	now;
	time_t	lmt;

	if (!philo)
		return (true);
	now = get_current_time(philo->prog);
	lmt = get_time(&philo->lmt, &philo->lmt_mtx);
	if (now - lmt > philo->prog->ttd)
	{
		write_status("died", philo);
		set_bool(&philo->prog->end, true, &philo->prog->end_mtx);
		return (true);
	}
	return (false);
}
