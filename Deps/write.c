/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:31:23 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"
#include "../philo.h"


void	write_status(t_philo *philo, e_status status)
{
	time_t	timestamp;
	char	*str;

	if (status == THINKING)
		str = "is thinking";
	if (status == EATING)
		str = "is EATING";
	if (status == SLEEPING)
		str = "is sleeping";
	if (status == TAKEN_FORK)
		str = "has taken a fork";
	if (status == DEAD)
		str = "died";
	timestamp = get_current_time(philo->program);
	set_mutex(&philo->program->printf_mtx, LOCK);
	printf("%ld %d %s", timestamp, philo->id, str);
	set_mutex(&philo->program->printf_mtx, UNLOCK);
}
