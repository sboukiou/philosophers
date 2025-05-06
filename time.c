/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:12:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:34:01 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./philo.h"
#include <sys/time.h>

time_t	get_current_time(t_program *prog, t_time unit)
{
	struct timeval	tv;
	struct timezone	tz;
	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		print_error(prog, "Failed to fetch current time (gettimeofday)");
		return (FAIL);
	}
	if (unit == MSEC)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	if (unit == USEC)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	if (unit == SEC)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	print_error(prog, "Wrong time unit given");
	return (FAIL);
}

/**
	* usnooze - pauses the calling thread for
	* a precise amount of time in m_seconds
	* @time: Time to sleep (in m-seconds)
	* Return: 0 if succeeded or -1
	*/
int	usnooze(t_program *prog, int time)
{
	time_t	start_time;
	time_t	elapsed_time;

	start_time = get_current_time(prog, MSEC);
	elapsed_time = get_current_time(prog, MSEC);
	if (elapsed_time == FAIL || start_time == FAIL)
		return (FAIL);
	while (elapsed_time < start_time + time)
	{
		usleep(10);
		elapsed_time = get_current_time(prog, MSEC);
		if (elapsed_time == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

time_t	get_time_of_last_meal(t_philo philo)
{
	return (philo.last_meal_time);
}
