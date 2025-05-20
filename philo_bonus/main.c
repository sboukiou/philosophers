/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:59:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/20 20:46:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

/*static void	children(t_program *prog)*/
/*{*/
/*	create_processes(prog);*/
/*	wait_for_others(prog);*/
/*	start_routine(prog);*/
/*}*/

static bool	are_philos_all_ready(t_program *prog)
{
	bool	val;

	sem_wait(prog->philos_all_ready_sem);
	val = prog->philos_all_ready;
	sem_post(prog->philos_all_ready_sem);
	return (val);
}

static bool	is_simulation_finished(t_program *prog)
{
	bool	val;

	sem_wait(prog->end_of_simulation_sem);
	val = prog->end_of_simulation;
	sem_post(prog->end_of_simulation_sem);
	return (val);
}

static void	wait_for_philos(t_program *prog)
{
	while (are_philos_all_ready(prog) == false)
		;
}

static bool	has_philo_starved(t_philo *philo)

static void	loop_checking(t_program *prog)
{
	t_philo	*philo;
	while (are_philos_all_ready(prog) == false)
		;
	while (is_simulation_finished(prog) == false)
	{
		for (int i = 0; i < prog->philo_count)
		{
			philo = prog->philos[i];
			if (has_philo_starved(philo) == true)
				stop_simulation(prog);
			i++;
		}
	}
}

static void	launch_monitor(t_program *prog)
{
	wait_for_philos(prog);
	loop_checking(prog);
}

/*static void	clean(t_program *prog)*/
/*{*/
/*	free_all_allocated_memory(prog);*/
/*}*/
/**/
int main(int ac, char **av)
{
	t_program	prog;

	get_data(ac, av, &prog);
	printf("After parser\n");
	printf("%d %d %d %d\n", prog.philo_count, prog.time_to_die, prog.time_to_eat, prog.time_to_sleep);
	initialize_program_data(&prog);
	launch_monitor(&prog);
	/*children(prog);*/
	/*clean(prog);*/
	return (0);
}
