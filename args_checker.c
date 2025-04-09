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

t_philo_data	*args_checker(int ac, char **av)
{
	t_philo_data	*philo_data;

	if (ac < 5 || ac > 6)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Number of arguments is invalid\n");
		return (NULL);
	}
	philo_data = (t_philo_data *)malloc(sizeof(t_philo_data));
	if (!philo_data)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Failed to allocate memory for philo_data\n");
		return (NULL);
	}
	philo_data->number_of_philos = _atoi(av[1]);
	if (philo_data->number_of_philos < 1 || philo_data->number_of_philos > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: Number of philosophers is invalid\n");
		free(philo_data);
		return (NULL);

	}
	philo_data->time_to_die = _atoi(av[2]);
	if (philo_data->time_to_die < 1 || philo_data->time_to_die > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to die given is invalid\n");
		free(philo_data);
		return (NULL);
	}
	philo_data->time_to_eat = _atoi(av[3]);
	if (philo_data->time_to_eat < 1 || philo_data->time_to_eat > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to eat given is invalid\n");
		free(philo_data);
		return (NULL);
	}
	philo_data->time_to_sleep = _atoi(av[4]);
	if (philo_data->time_to_sleep < 1 || philo_data->time_to_sleep > INT_MAX)
	{
		dprintf(STDERR_FILENO, "[ERROR]: time to sleep given is invalid\n");
	}
	if (av[5])
	{
		philo_data->times_each_must_eat = _atoi(av[5]);
		if (philo_data->times_each_must_eat < 0 || philo_data->times_each_must_eat > INT_MAX)
		{
			dprintf(STDERR_FILENO, "[ERROR]: times each philosopher must eat given is invalid\n");
			free(philo_data);
			return (NULL);
		}
	}
	philo_data->philos= (t_philosopher *)malloc(sizeof(t_philosopher) * philo_data->number_of_philos);
	if (philo_data->philos == NULL)
	{
		free(philo_data);
		printf("[ERROR]: Failed to allocate philosophers\n");
		return (NULL);
	}
	return (philo_data);
}
