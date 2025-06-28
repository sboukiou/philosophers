# include "./philo.h"

static void	eat(t_philo *philo)
{
	if (end(philo))
		return ;
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	write_status(BGREEN"is eating", philo->id, philo->prog);
	ft_usleep(philo->prog, philo->prog->tte);
	set_mutex(philo->left_fork, UNLOCK);
	set_mutex(philo->right_fork, UNLOCK);
}

static void	snooze(t_philo *philo)
{
	if (end(philo))
		return ;
	write_status(BBLUE"is sleeping", philo->id, philo->prog);
	ft_usleep(philo->prog, philo->prog->tts);
}

static void	think(t_philo *philo)
{
	if (end(philo))
		return ;
	write_status(UPURPLE"is thinking", philo->id, philo->prog);
}

static void *routine(void *arg)
{
	t_philo	*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	philo = (t_philo *)arg;
	while (get_bool(&philo->prog->ready, &philo->prog->ready_mtx) == false)
		;
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	while (true)
	{
		if (end(philo))
			return (NULL);
		if (philo->prog->pc == 1)
		{
			single_philo(philo);
			return (NULL);
		}
		assign_forks(philo, &first_fork, &second_fork);
		if (philo->id % 2)
			usleep(300);
		take_fork(first_fork, philo);
		take_fork(second_fork, philo);
		eat(philo);
		if (end(philo))
			return (NULL);
		snooze(philo);
		if (end(philo))
			return (NULL);
		think(philo);
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

