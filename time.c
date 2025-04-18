/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:12:29 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 15:13:38 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/time.h>

void	custom_usleep(int time)
{
	struct timeval	tv_start;
	struct timeval	tv_end;
	struct timezone	tz_start;
	struct timezone	tz_end;

	gettimeofday(&tv_start, &tz_start);
	gettimeofday(&tv_end, &tz_end);
	while (tv_end.tv_usec < tv_start.tv_usec + time - 1)
		gettimeofday(&tv_end, &tz_end);

}

