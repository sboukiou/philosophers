# include "./philo.h"

static void	wait_philos(t_philo *philo)
{
	bool	ready;

	ready = get_bool(&philo->prog->ready, &philo->prog->ready_mtx);
	while (ready == false)
		ready = get_bool(&philo->prog->ready, &philo->prog->ready_mtx);
}


void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	wait_philos(philo);
	while (true)
	{
		if (philo->id % 2)
		{
			set_mutex(&philo->left_fork, LOCK);
		}
	}
	return (NULL);
}
