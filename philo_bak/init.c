# include "./philo.h"

int	init(t_prog *prog)
{
	int		count;
	t_philo	*philo;

	if (!prog)
		return (EXIT_FAILURE);
	prog->philos = (t_philo *)malloc(sizeof(t_philo) * prog->pc);
	if (!prog->philos)
	{
		printf(BRED"Failed to allocate philosophers [t_philo]\n"RESET);
		return (EXIT_FAILURE);
	}
	memset(prog->philos, '\0', sizeof(t_philo) * prog->pc);
	prog->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * prog->pc);
	if (!prog->forks)
	{
		printf(BRED"Failed to allocate philosophers [t_philo]\n"RESET);
		free(prog->philos);
		return (EXIT_FAILURE);
	}
	memset(prog->forks, '\0', sizeof(pthread_mutex_t) * prog->pc);
	count = 0;
	while (count < prog->pc)
	{
		philo = prog->philos + count;
		philo->mc = 0;
		philo->prog =  prog;
		philo->id = count + 1;
		philo->right_fork = prog->forks + philo->id - 1;
		philo->left_fork = prog->forks + (philo->id % prog->pc);
		if (set_mutex(&philo->mc_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&philo->lmt_mtx, INIT) != SUCCESS)
			return (FAIL);
		if (set_mutex(&prog->forks[count], INIT) != SUCCESS)
			return (FAIL);
		count++;
	}
	if (set_mutex(&prog->ready_mtx, INIT) != SUCCESS)
		return (FAIL);
	if (set_mutex(&prog->end_mtx, INIT) != SUCCESS)
		return (FAIL);
	return (EXIT_SUCCESS);
}
