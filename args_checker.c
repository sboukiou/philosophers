/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:38:46 by sboukiou          #+#    #+#             */
/*   Updated: 2025/03/20 12:56:49 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*NOTE: All dprintf's need to be replaced by a write to STDERR*/

t_program_info	*args_checker(int ac, char **av)
{
	t_program_info	*program_info;

	if (ac < 5 || ac > 6)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Number of arguments is invalid\n");
		return (NULL);
	}
	program_info = (t_program_info *)malloc(sizeof(t_program_info));
	if (!program_info)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Failed to allocate memory for program_info\n");
		return (NULL);
	}
	program_info->number_of_philos = _atoi(av[1]);
	if (program_info->number_of_philos < 1 || program_info->number_of_philos > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Number of philosophers is invalid\n");
		free(program_info);
		return (NULL);

	}
	program_info->time_to_die = _atoi(av[2]);
	if (program_info->time_to_die < 1 || program_info->time_to_die > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to die given is invalid\n");
		free(program_info);
		return (NULL);
	}
	program_info->time_to_eat = _atoi(av[3]);
	if (program_info->time_to_eat < 1 || program_info->time_to_eat > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to eat given is invalid\n");
		free(program_info);
		return (NULL);
	}
	program_info->time_to_sleep = _atoi(av[4]);
	if (program_info->time_to_sleep < 1 || program_info->time_to_sleep > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to sleep given is invalid\n");
	}
	if (av[5])
	{
		program_info->times_each_must_eat = _atoi(av[5]);
		if (program_info->times_each_must_eat < 0 || program_info->times_each_must_eat > INT_MAX)
		{
			dprintf(STDERR_FILENO, "[ERROR]: times each philosopher must eat given is invalid\n");
			free(program_info);
			return (NULL);
		}
	}
	program_info->philos= (t_philosopher *)malloc(sizeof(t_philosopher) * program_info->number_of_philos);
	if (program_info->philos == NULL)
	{
		free(program_info);
		printf("[ERROR]: Failed to allocate philosophers\n");
		return (NULL);
	}
	return (program_info);
}
