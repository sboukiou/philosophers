/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:46:21 by sboukiou          #+#    #+#             */
/*   Updated: 2025/06/28 08:54:35 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

time_t	get_current_time(void)
{
	struct timeval	tv;
	struct timezone	tz;
	time_t			current_time;

	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		printf(BRED"Failed to fetch current time (gettimeofday)"RESET);
		return (FAIL);
	}
	current_time = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (current_time);
}

/**
	* ft_usleep - pauses the calling thread for
	* a precise amount of time in m_seconds
	* @time: Time to sleep (in m-seconds)
	* Return: 0 if succeeded or -1
	*/
int	ft_usleep(int time)
{
	time_t	start_time;
	time_t	elapsed_time;

	start_time = get_current_time();
	elapsed_time = get_current_time();
	if (elapsed_time == FAIL || start_time == FAIL)
		return (FAIL);
	while (elapsed_time < start_time + time)
	{
		usleep(400);
		elapsed_time = get_current_time();
		if (elapsed_time == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}
