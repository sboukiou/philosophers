/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:22:20 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/01 17:17:24 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*[DATA]: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]*/
t_program	*parser(int ac, char **av)
{
	t_program	*program;

	if (ac != 5 && ac != 6)
	{
		print_error(NULL, "Number of arguments is incorrect");
		print_info(NULL, "Usage: ./philo number_of_philos time_to_eat time_to_sleep tim_to_die [number_of_meals]");
		return (NULL);
	}
	if (_atoi(av[1]) < 1 || _atoi(av[2]) < 1  ||
		_atoi(av[3]) < 1 || _atoi(av[4]) < 2)
	{
		print_error(NULL, "Invalid arguments given ! Try again");
		return (NULL);
	}
	if (ac == 6 && _atoi(av[5]) < 1)
	{
		print_error(NULL, "Invalid arguments given ! Try again");
		return (NULL);
	}
	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
	{
		print_error(NULL, "Failed to allocate resources !");
		return (NULL);
	}
	memset(program, '\0', sizeof(t_program));
	program->philo_count = _atoi(av[1]);
	program->time_to_die = _atoi(av[2]);
	program->time_to_eat = _atoi(av[3]);
	program->time_to_sleep = _atoi(av[4]);
	if (ac == 6)
		program->number_of_meals = _atoi(av[5]);
	else
		program->number_of_meals = -1;
	return (program);
}
