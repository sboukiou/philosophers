/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:27:19 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/19 10:11:39 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	thinking(t_philo *philo, int time)
{
	long long	now;
	now = get_actual_time_msec(philo->program);
	printf("%lld\n", now);
	print_thinking(philo->program, philo->id, now - philo->program->start_time);
	ft_usleep(THINKING_TIME);
}
