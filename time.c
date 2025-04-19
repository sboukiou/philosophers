/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:12:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 09:54:08 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./philo.h"
#include <sys/time.h>

/**
	* ft_usleep - pauses the calling thread for
	* a precise amount of time in m_seconds
	* @time: Time to sleep (in m-seconds)
	* Return: 0 if succeeded or -1
	*/
int	ft_usleep(int time)
{
	struct timeval	tv_start;
	struct timeval	tv_end;
	struct timezone	tz_start;
	struct timezone	tz_end;

	if (gettimeofday(&tv_start, &tz_start))
		return (FAIL);
	if (gettimeofday(&tv_end, &tz_end))
		return (FAIL);
	while (tv_end.tv_usec < tv_start.tv_usec + time * 1000)
		if (gettimeofday(&tv_end, &tz_end))
			return (FAIL);
	return (SUCCESS);
}

long long	get_actual_time_msec(t_program *program)
{
	struct timeval	tv;
	struct timeval	tz;

	if (gettimeofday(&tv, &tz))
	{
		print_error(program, "gettimeofday failed !");
		exit(0);
	}
	return((long long)(tv.tv_usec / 1000));
}
