/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:49:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:49:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static bool	philo_full(t_philo *philo)
{
	if (philo->mc == philo->prog->mc)
		return (true);
	return (false);
}

static bool	dead(t_philo *philo)
{
	time_t	now;

	if (!philo)
		return (true);
	now = get_current_time(philo->prog);
	if (now - get_time(&philo->lmt, &philo->lmt_mtx) > philo->prog->ttd)
		return (true);
	return (false);
}

void	*monitor(void *arg)
{
	t_prog	*prog;
	int		i;
	int		full_philos;

	if (!arg)
		return (NULL);
	prog = (t_prog *)arg;
	while (get_bool(&prog->ready, &prog->ready_mtx) == false)
		;
	while (true)
	{
		i = 0;
		usleep(1000);
		full_philos = 0;
		while (i < prog->pc)
		{
			if (dead(prog->philos + i) == true)
			{
				write_status("died", prog->philos + i);
				set_bool(&prog->end, true, &prog->end_mtx);
				return (NULL);
			}
			if (philo_full(prog->philos + i) == true)
				full_philos += 1;
			if (full_philos == prog->pc)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
