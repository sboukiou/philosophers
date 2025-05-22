#include "./philo_bonus.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void	philo_routine(t_philo *philo)
{
	sem_t	*forks_sem;
	if (!philo)
		return ;
	print_info(philo->program, "Child initialized\n");
	forks_sem = sem_open("forks_sem", O_EXCL);
	if (forks_sem == SEM_FAILED)
		print_error(philo->program, "failed to open forks sem");
	while (true)
	{
		sem_wait(forks_sem);
		write_status(philo, TAKEN_FORK);
		sem_wait(forks_sem);
		write_status(philo, TAKEN_FORK);
		usleep(philo->program->time_to_eat * 1000);
		write_status(philo, EATING);
		sem_post(forks_sem);
		sem_post(forks_sem);
		usleep(philo->program->time_to_sleep * 1000);
		write_status(philo, SLEEPING);
		write_status(philo, THINKING);
		printf("ENNNNNNND\n");
	}
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
			else if (current != 0 && getpid() == main)
				prog->philos[i].pid = current;
		}
	}
	sem_wait(prog->philos_all_ready_sem);
	prog->philos_all_ready = true;
	sem_post(prog->philos_all_ready_sem);
	if (getpid() == main)
	{
		for (int i = 0; i < prog->philo_count; i++)
			waitpid(prog->philos[i].pid, NULL, 0);
	}
}

