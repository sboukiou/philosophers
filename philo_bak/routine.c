# include "./philo.h"


static void *routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_bool(&philo->prog->ready, &philo->prog->ready_mtx) == false)
		;
	while (true)
	{
		if (philo->id % 2 == 0)
		{
			set_mutex(philo->left_fork, LOCK);
			write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
			set_mutex(philo->right_fork, LOCK);
			write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
		}
		else
		{
			set_mutex(philo->right_fork, LOCK);
			write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
			set_mutex(philo->left_fork, LOCK);
			write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
		}
		write_status(BGREEN"is eating", philo->id, philo->prog);
		ft_usleep(philo->prog, philo->prog->tte);
		set_mutex(philo->left_fork, UNLOCK);
		set_mutex(philo->right_fork, UNLOCK);
		philo->lmt = get_current_time(philo->prog);
		philo->mc += 1;
		if (philo->mc == philo->prog->mc)
			return (NULL);
		write_status(UPURPLE"is sleeping", philo->id, philo->prog);
		ft_usleep(philo->prog, philo->prog->tts);
		write_status(BBLUE"is thinking", philo->id, philo->prog);
	}
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
		set_mutex(&prog->write_mtx, LOCK);
		set_mutex(&prog->write_mtx, UNLOCK);
		if (pthread_check != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	set_time(&prog->start, &prog->start_mtx, 0);
	set_time(&prog->start, &prog->start_mtx, get_current_time(prog));
	set_bool(&prog->ready, true, &prog->ready_mtx);
	return (EXIT_SUCCESS);
}

