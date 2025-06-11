/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:10:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:37 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	set_mutex(pthread_mutex_t *mutex, t_mtx action)
{
	if (action == INIT)
		return (pthread_mutex_init(mutex, NULL));
	if (action == LOCK)
		return (pthread_mutex_lock(mutex));
	if (action == UNLOCK)
		return (pthread_mutex_unlock(mutex));
	if (action == DESTROY)
		return (pthread_mutex_destroy(mutex));
	return (FAIL);
}

bool	get_bool(bool *target, pthread_mutex_t *mtx)
{
	bool	value;

	set_mutex(mtx, LOCK);
	value = *target;
	set_mutex(mtx, UNLOCK);
	return (value);
}

void	set_bool(bool *target, bool value, pthread_mutex_t *mtx)
{
	set_mutex(mtx, LOCK);
	*target = value;
	set_mutex(mtx, UNLOCK);
}

bool	get_priority(t_philo *philo)
{
	int			iter;
	time_t		last_meal_time;
	time_t		val;
	t_program	*prog;

	if (!philo || !philo->program)
		return (false);
	prog = philo->program;
	iter = 0;
	last_meal_time = philo->last_meal_time;
	while (iter < prog->philo_count)
	{
		val = prog->philos->last_meal_time;
		if (val < last_meal_time)
			return (false);
		iter++;
	}
	return (true);
}

int	get_number(int *target, pthread_mutex_t *mtx)
{
	int	value;

	if (!target)
		return (-1);
	set_mutex(mtx, LOCK);
	value = *target;
	set_mutex(mtx, UNLOCK);
	return (value);
}

void	set_number(int *target, int value, pthread_mutex_t *mtx)
{
	set_mutex(mtx, LOCK);
	*target = value;
	set_mutex(mtx, UNLOCK);
}

e_status	get_status(t_philo *philo)
{
	e_status	val;
	if (!philo)
		return (DEAD);
	set_mutex(&philo->status_mtx, LOCK);
	val = philo->status;
	set_mutex(&philo->status_mtx, UNLOCK);
	return (val);
}

void	set_status(t_philo *philo, e_status status)
{
	if (!philo)
		return ;
	set_mutex(&philo->status_mtx, LOCK);
	philo->status = status;
	set_mutex(&philo->status_mtx, UNLOCK);
}
