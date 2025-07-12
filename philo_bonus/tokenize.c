/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:51:42 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/12 01:33:18 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	check_input(t_prog *prog, int ac, char **av)
{
	if (!prog)
	{
		printf(BRED"Unable to get info, program given is null\n"RESET);
		return (EXIT_FAILURE);
	}
	if (ac != 5 && ac != 6)
	{
		printf(BRED"Number of arguments is incorrect\n"RESET);
		printf(BYELLOW"Usage: ./philo pc tte tts ttd [mc]\n"RESET);
		return (EXIT_FAILURE);
	}
	if (ft_atoi(av[1]) == 0)
	{
		printf(UPURPLE"No philosophers provided, No dinner served\n"RESET);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	tokenize(t_prog *prog, int ac, char **av)
{
	if (check_input(prog, ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
	{
		printf(BRED"Invalid arguments given ! Try again"RESET);
		return (EXIT_FAILURE);
	}
	if (ac == 6 && ft_atoi(av[5]) < 1)
	{
		printf(BRED"Invalid arguments given ! Try again"RESET);
		return (EXIT_FAILURE);
	}
	prog->pc = ft_atoi(av[1]);
	prog->ttd = ft_atoi(av[2]);
	prog->tte = ft_atoi(av[3]);
	prog->tts = ft_atoi(av[4]);
	if (ac == 6)
		prog->mc = ft_atoi(av[5]);
	else
		prog->mc = -1;
	return (EXIT_SUCCESS);
}
