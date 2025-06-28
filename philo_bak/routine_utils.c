# include "./philo.h"

void	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	set_mutex(fork, LOCK);
	if (end(philo))
	{
		set_mutex(fork, UNLOCK);
		return ;
	}
	write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
}

void	assign_forks(t_philo *philo, pthread_mutex_t **first_fork, pthread_mutex_t **second_fork)
{
		if (philo->id % 2 == 0)
		{
			*first_fork = philo->left_fork;
			*second_fork = philo->right_fork;
		}
		else
		{
			*first_fork = philo->right_fork;
			*second_fork = philo->left_fork;
		}
}

void	single_philo(t_philo *philo)
{
			set_mutex(philo->left_fork, LOCK);
			write_status(BYELLOW"has taken a fork", philo->id, philo->prog);
			set_mutex(philo->left_fork, UNLOCK);
			while (get_bool(&philo->prog->end, &philo->prog->end_mtx) == false)
				;
}

bool end(t_philo *philo)
{
	if (!philo)
		return (true);
	if (get_bool(&philo->prog->end, &philo->prog->end_mtx) == true)
		return (true);
	return (false);
}
