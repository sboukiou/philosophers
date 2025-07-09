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
	write_status(BYELLOW"has taken a fork", philo);
	set_mutex(philo->left_fork, UNLOCK);
	while (get_bool(&philo->prog->end, &philo->prog->end_mtx) == false)
		;
}

bool	end(t_philo *philo)
{
	if (!philo)
		return (true);
	if (get_bool(&philo->prog->end, &philo->prog->end_mtx) == true)
		return (true);
	return (false);
}
