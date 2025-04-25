/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:21:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/21 16:18:21 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "./Deps/deps.h"

int main(int ac, char **av)
{
	t_program	*program;

	program = parser(ac, av);
	init(program);
	monitor(program);
	for (int i = 0; i < program->philo_count; i++)
		pthread_join(program->philos[i].thread_id, NULL);
	print_info(program, "All philosophers are now ready and set");
	// simulate_dinner(program);
	cleanup(program);
	return (0);
}
