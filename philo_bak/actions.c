# include "./philo.h"


int	write_status(const char *status, t_philo *philo)
{
	time_t	now;

	now = get_current_time(philo->prog);
	set_mutex(&philo->prog->write_mtx, LOCK);
	if (end(philo))
	{
		set_mutex(&philo->prog->write_mtx, UNLOCK);
		return (0);
	}
	printf("[%8lu] %d %s\n"RESET, now, philo->id, status);
	set_mutex(&philo->prog->write_mtx, UNLOCK);
	return (0);
}


void	eat(t_philo *philo)
{
	if (end(philo))
		return ;
	set_time(&philo->lmt, &philo->lmt_mtx, get_current_time(philo->prog));
	write_status(BGREEN"is eating", philo);
	ft_usleep(philo->prog, philo->prog->tte);
	set_mutex(philo->left_fork, UNLOCK);
	set_mutex(philo->right_fork, UNLOCK);
}

void	snooze(t_philo *philo)
{
	write_status(BBLUE"is sleeping", philo);
	ft_usleep(philo->prog, philo->prog->tts);
}

void	think(t_philo *philo)
{
	write_status(UPURPLE"is thinking", philo);
}
