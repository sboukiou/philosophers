/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:07:57 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/07 14:51:13 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

# define THREAD_COUNT 12

void	*routine(void *t_idx)
{
	printf("[INFO]: Thread N [%d] created\n", *(int *)t_idx);
	usleep(200);
	return (NULL);
}

int main(int ac, char **av)
{
	t_program_info	*program_info;
	int		creation;
	int		joining;

	program_info = args_checker(ac, av);
	if (!program_info)
		return (-1);
	printf("Number of philosophers: %d\n", program_info->number_of_philos);
	printf("Time to die: %d\n", program_info->time_to_die);
	printf("Time to eat: %d\n", program_info->time_to_eat);
	printf("Time to sleep: %d\n", program_info->time_to_sleep);
	printf("Number of meals each philosopher shall eat : %d\n\n", program_info->times_each_must_eat);
	for (int i = 0; i < program_info->number_of_philos; i++)
	{
		creation = pthread_create(&program_info->philos[i].thread, NULL, routine, (void *)&i);
		if (creation != 0)
		{
			printf("[ERROR]: Failed to create thread number %d\n", i);
			exit(0);
		}
	}
	for (int i = 0; i < program_info->number_of_philos; i++)
	{
		joining = pthread_join(program_info->philos[i].thread, NULL);
		if (joining != 0)
		{
			printf("[ERROR]: Failed to join thread number %d\n", i);
		}
	}
	free(program_info->philos);
	free(program_info);
	return (0);
}
