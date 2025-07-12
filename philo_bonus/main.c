/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 08:49:03 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/12 01:34:12 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int	close_semaphores(t_prog *prog)
{
	if (sem_close(prog->ready_sem) == FAIL)
		return (FAIL);
	if (sem_close(prog->write_sem) == FAIL)
		return (FAIL);
	if (sem_close(prog->monitor_start_sem) == FAIL)
		return (FAIL);
	if (sem_close(prog->forks) == FAIL)
		return (FAIL);
	if (sem_close(prog->glob_end) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_prog		prog;
	int			status;
	int			i;

	if (tokenize(&prog, ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init(&prog) == EXIT_FAILURE)
		return (printf("[Failed to init program data]\n"), EXIT_FAILURE);
	create_processes(&prog);
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == DEAD)
	{
		i = 0;
		while (i < prog.pc)
			kill(prog.philos[i++].pid, SIGKILL);
	}
	else if (WEXITSTATUS(status) == FULL)
		while (waitpid(-1, &status, 0) > 0)
			;
	close_semaphores(&prog);
	free(prog.philos);
	return (0);
}
