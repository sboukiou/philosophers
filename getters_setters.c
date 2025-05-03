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
	int	iter;
	int	meal_count;

	if (!philo || !philo->program)
		return (false);
	iter = 0;
	meal_count = philo->meal_count;
	while (iter < philo->program->philo_count)
	{
		if (philo->program->philos[iter].meal_count < meal_count)
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

bool get_all_eaten(t_program *program)
{
	int	iter;
	int	value;

	if (!program || !program->philos)
		return (print_info(NULL, "Failed to find prog or philos"), false);
	iter = 0;
	usleep(60);
	while (iter < program->philo_count)
	{
		value = get_number(&program->philos[iter].meal_count, &program->philos[iter].meal_count_mtx);
		set_mutex(&program->printf_mtx, LOCK);
		set_mutex(&program->printf_mtx, UNLOCK);
		if (value < program->number_of_meals)
			return (false);
		iter++;
		usleep(60);
	}
	return (true);
}

bool	get_forks_available(t_philo *philo)
{
	if (get_bool(&philo->left_fork->taken, &philo->left_fork->taken_mtx) == true)
		return (false);
	if (get_bool(&philo->right_fork->taken, &philo->right_fork->taken_mtx) == true)
		return (false);
	return (true);
}
