#include "./philo_bonus.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void	philo_routine(t_philo *philo)
{
	if (!philo)
		return ;
	print_info(philo->program, "A philo_created\n");
	exit(0);
}

void	children(t_program *prog)
{
	pid_t	current;
	pid_t	main;

	if (!prog)
		return ;
	main = getpid();
	for (int i = 0; i < prog->philo_count; i++)
	{
		if (getpid() == main)
		{
			prog->philos[i].id = i + 1;
			current = fork();
			if (current == 0 && getppid() == main)
				philo_routine(&prog->philos[i]);
			else if (current != 0)
				prog->philos[i].pid = current;
		}
	}
	sem_wait(prog->philos_all_ready_sem);
	prog->philos_all_ready = true;
	sem_post(prog->philos_all_ready_sem);
	for (int i = 0; i < prog->philo_count; i++)
		waitpid(prog->philos[i].pid, NULL, EXIT_SUCCESS);
}

