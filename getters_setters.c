/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:10:36 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 20:25:34 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


void	act_mutex(pthread_mutex_t *mutex, t_mtx action)
{
	if (action == INIT)
		pthread_mutex_init(mutex, NULL);
	if (action == LOCK)
		pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (action == DESTROY)
		pthread_mutex_destroy(mutex);
}

bool	bool_getter(bool *target, pthread_mutex_t *mtx)
{
	bool	value;

	act_mutex(mtx, LOCK);
	value = *target;
	act_mutex(mtx, UNLOCK);
	return (value);
}

void	bool_setter(bool *target, bool value, pthread_mutex_t *mtx)
{
	act_mutex(mtx, LOCK);
	*target = value;
	act_mutex(mtx, UNLOCK);
}
