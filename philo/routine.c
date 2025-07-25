/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:49:38 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/12 01:12:02 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	start_ritual(t_philo *philo)
{
	while (get_bool(&philo->prog->ready, &philo->prog->ready_mtx) == false)
		;
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	if (philo->prog->pc == 1)
	{
		single_philo(philo);
		return (1);
	}
	return (0);
}

static void	*routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	philo = (t_philo *)arg;
	if (start_ritual(philo))
		return (NULL);
	assign_forks(philo, &first_fork, &second_fork);
	while (true)
	{
		if (philo->id % 2 != 0)
			usleep(280);
		if (end(philo))
			return (NULL);
		if (philo->prog->pc == 1)
			return (single_philo(philo), NULL);
		if (eat(philo, first_fork, second_fork))
			return (NULL);
		if (snooze(philo))
			return (NULL);
		if (think(philo))
			return (NULL);
	}
	return (NULL);
}

int	simulation(t_prog *prog)
{
	int	i;
	int	pthread_check;

	if (!prog)
		return (EXIT_FAILURE);
	i = 0;
	while (i < prog->pc)
	{
		pthread_check = pthread_create(&prog->philos[i].thread,
				NULL, routine, prog->philos + i);
		if (pthread_check != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	set_time(&prog->start, &prog->start_mtx, 0);
	set_time(&prog->start, &prog->start_mtx, get_current_time(prog));
	set_bool(&prog->ready, true, &prog->ready_mtx);
	return (EXIT_SUCCESS);
}
