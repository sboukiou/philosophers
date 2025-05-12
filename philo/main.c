/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:21:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/05 13:49:47 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "./Deps/deps.h"

static int	join_all_threads(t_program *prog)
{
	int	count;

	if (!prog)
		return (FAIL);
	count = 0;
	while (count < prog->philo_count)
	{
		if (pthread_join(prog->philos[count].thread_id, NULL) != SUCCESS)
			return (print_info(prog, "Failed to join the thread"), FAIL);
		count++;
	}
	if (pthread_join(prog->monitor, NULL) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int main(int ac, char **av)
{
	t_program	*program;

	program = parser(ac, av);
	if (program == NULL)
		return (FAIL);
	if (init(program) != SUCCESS)
		return (FAIL);
	if (start_dinner(program) != SUCCESS)
		return (FAIL);
	if (join_all_threads(program) != SUCCESS)
		return (FAIL);
	cleanup(program);
	return (SUCCESS);
}
