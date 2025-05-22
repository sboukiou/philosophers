/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:59:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/21 13:48:55 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

/*static void	children(t_program *prog)*/
/*{*/
/*	create_processes(prog);*/
/*	wait_for_others(prog);*/
/*	start_routine(prog);*/
/*}*/

int main(int ac, char **av)
{
	t_program	prog;

	get_data(ac, av, &prog);
	printf("After parser\n");
	printf("%d %d %d %d\n", prog.philo_count, prog.time_to_die, prog.time_to_eat, prog.time_to_sleep);
	initialize_program_data(&prog);
	printf(BBLUE"After program data init\n"RESET);
	launch_monitor(&prog);
	children(&prog);
	pthread_join(prog.monitor, NULL);
	/*clean(prog);*/
	return (0);
}
