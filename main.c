/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:21:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/01 18:11:59 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "./Deps/deps.h"

int	wait_for_threads(t_program *prog)
{
	int	count;

	if (!prog)
		return (FAIL);
	count = 0;
	while (count < prog->philo_count)
	{
		pthread_join(prog->philos[count].thread_id, NULL);
		count++;
	}
	return (SUCCESS);
}

int main(int ac, char **av)
{
	t_program	*program;

	print_info(NULL, "Parser: ");
	program = parser(ac, av);
	if (program == NULL)
		return (SUCCESS);
	print_info(NULL, "Init : ");
	if (init(program) != SUCCESS)
		return (SUCCESS);
	if (wait_for_threads(program) != SUCCESS)
		return (SUCCESS);
	print_info(NULL, "Cleanup: ");
	cleanup(program);
	return (0);
}
