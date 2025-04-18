/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:21:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 19:57:18 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "./Deps/deps.h"

bool	get_philos_ready(t_program *program)
{
	bool	value;

	pthread_mutex_lock(&program->philos_ready_mtx);
	value = program->philos_ready;
	pthread_mutex_unlock(&program->philos_ready_mtx);
	return (value);
}

int main(int ac, char **av)
{
	t_program	*program;

	program = parser(ac, av);
	init(program);
	while (get_philos_ready(program) == false)
		;
	for (int i = 0; i < program->philo_count; i++)
		pthread_join(program->philos[i].thread_id, NULL);
	print_info("All philosophers are now ready and set");
	// simulate_dinner(program);
	cleanup(program);
	return (0);
}
