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

time_t	get_current_time(t_program *prog)
{
	struct timeval	tv;
	struct timezone	tz;
	time_t	current_time;
	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		print_error(prog, "Failed to fetch current time (gettimeofday)");
		return (FAIL);
	}
		current_time = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
		return (current_time - prog->start_time);
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

	start_time = get_current_time(prog);
	elapsed_time = get_current_time(prog);
	if (elapsed_time == FAIL || start_time == FAIL)
		return (FAIL);
	while (elapsed_time < start_time + time)
	{
		if (get_bool(&prog->end_of_simu, &prog->end_of_simu_mtx) == true)
			return (SUCCESS);
		usleep(150);
		elapsed_time = get_current_time(prog);
		if (elapsed_time == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

time_t	get_time_of_last_meal(t_philo philo)
{
	return (philo.last_meal_time);
}
