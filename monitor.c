/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:19:27 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:35:27 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
/**/
/*void	*monitor_routine(void *arg)*/
/*{*/
/*	int		iter;*/
/*	t_program	*prog;*/
/**/
/**/
/*	if (arg == NULL)*/
/*		return (NULL);*/
/*	prog = (t_program *)arg;*/
/*	iter = 0;*/
/*	while (get_all_eaten(prog) == false &&*/
/*	get_bool(&prog->all_philos_full, &prog->all_philos_full_mtx) == false)*/
/*	{*/
/*		for (int i = 0; i < prog->philo_count; i++)*/
/*		{*/
/*			if (get_current_time_msec(prog) - get_time_of_last_meal(prog->philos[i]) > prog->time_to_die)*/
/*			{*/
/*				died(&prog->philos[i]);*/
/*				exit(0);*/
/*				set_bool(&prog->philo_died, true, &prog->philo_died_mtx);*/
/*				cleanup(prog);*/
/*			}*/
/*		}*/
/*	}*/
/*	return (NULL);*/
/*}*/
