# include "./philo.h"

void join_all_threads(t_prog *prog);

int main(int ac, char **av)
{
	t_prog	prog;
	pthread_t	mthread;

	if (tokenize(&prog, ac, av) == EXIT_FAILURE)
		return (0);
	if (init(&prog) == EXIT_FAILURE)
		return (0);

	if (pthread_create(&mthread, NULL, monitor, &prog) != EXIT_SUCCESS)
		return (0);
	if (simulation(&prog) == EXIT_FAILURE)
		return (0);
	join_all_threads(&prog);
	pthread_join(mthread, NULL);
	free(prog.philos);
	free(prog.forks);
	return (0);

}


void	join_all_threads(t_prog *prog)
{
	int	i;

	if (!prog)
		return ;
	i = 0;
	while (i < prog->pc)
	{
		if (pthread_join(prog->philos[i].thread, NULL) != EXIT_SUCCESS)
			return ;
		i++;
	}
}
