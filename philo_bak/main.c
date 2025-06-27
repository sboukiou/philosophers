# include "./philo.h"


int	init(t_prog *prog);

int main(int ac, char **av)
{
	t_prog	prog;

	if (tokenize(&prog, ac, av) == EXIT_FAILURE)
		return (0);
	if (init(&prog) == EXIT_FAILURE)
		return (0);
	free(prog.philos);
	free(prog.forks);
	return (0);

}

static void *routine(void *arg)
{
	(void)arg;
	return (NULL);
}

int	simulation(t_prog *prog)
{
	int	i;
	int	pthread_check;

	if (!prog)
		return (EXIT_FAILURE);
	i = 0;
	while (i < prog->pc)
	{
		pthread_check = pthread_create(&prog->philos[i].thread, NULL, routine, prog->philos + i);
		if (pthread_check == FAIL)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
