# include "./philo.h"

int	tokenize(t_prog *prog, int ac, char **av)
{
	int	i;

	if (!prog)
	{
		printf(BRED"Unable to get info, program given is null\n"RESET);
		return (EXIT_FAILURE);
	}
	if (ac != 5 && ac != 6)
	{
		printf(BRED"Number of arguments is incorrect\n"RESET);
		printf(BYELLOW"Usage: ./philo pc tte tts ttd [mc]\n"RESET);
		return (EXIT_FAILURE);
	}
	i = 0;
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 1  ||
		ft_atoi(av[3]) < 1 || ft_atoi(av[4]) < 2)
	{
		printf(BRED"Invalid arguments given ! Try again"RESET);
		return (EXIT_FAILURE);
	}
	if (ac == 6 && ft_atoi(av[5]) < 1)
	{
		printf(BRED"Invalid arguments given ! Try again"RESET);
		return (EXIT_FAILURE);
	}
	prog->pc = ft_atoi(av[1]);
	prog->ttd = ft_atoi(av[2]);
	prog->tte = ft_atoi(av[3]);
	prog->tts = ft_atoi(av[4]);
	if (ac == 6)
		prog->mc = ft_atoi(av[5]);
	else
		prog->mc = -1;
	return (EXIT_SUCCESS);
}
