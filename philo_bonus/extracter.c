/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/19 09:11:22 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*[DATA]: ./philo [number_of_philosophers]
 * [time_to_die]
 * [time_to_eat]
 * [time_to_sleep]
 * [number_of_times_each_philosopher_must_eat]
 **/
void	get_data(int ac, char **av, t_program *prog)
{

	if (ac != 5 && ac != 6)
	{
		printf(BRED"Number of arguments is incorrect\n"RESET);
		printf(BYELLOW"Usage: ./philo number_of_philos time_to_eat time_to_sleep tim_to_die [number_of_meals]\n"RESET);
		exit(0);
	}
	if (_atoi(av[1]) < 2 || _atoi(av[2]) < 1  ||
		_atoi(av[3]) < 1 || _atoi(av[4]) < 2)
	{
		printf(BRED"Invalid arguments given ! Try again\n"RESET);
		exit(0);
	}
	if (ac == 6 && _atoi(av[5]) < 1)
	{
		printf(BRED"Invalid arguments given ! Try again\n"RESET);
		exit(0);
	}
	prog->philo_count = _atoi(av[1]);
	prog->time_to_die = _atoi(av[2]);
	prog->time_to_eat = _atoi(av[3]);
	prog->time_to_sleep = _atoi(av[4]);
	if (ac == 6)
		prog->number_of_meals = _atoi(av[5]);
	else
		prog->number_of_meals = -1;
}
