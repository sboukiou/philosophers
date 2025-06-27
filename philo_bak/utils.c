#include "./philo.h"

int	set_mutex(pthread_mutex_t *mutex, t_mtx action)
{
	if (action == INIT)
		return (pthread_mutex_init(mutex, NULL));
	if (action == LOCK)
		return (pthread_mutex_lock(mutex));
	if (action == UNLOCK)
		return (pthread_mutex_unlock(mutex));
	if (action == DESTROY)
		return (pthread_mutex_destroy(mutex));
	return (FAIL);
}

bool	get_bool(bool *target, pthread_mutex_t *mtx)
{
	bool	value;

	set_mutex(mtx, LOCK);
	value = *target;
	set_mutex(mtx, UNLOCK);
	return (value);
}

void	set_bool(bool *target, bool value, pthread_mutex_t *mtx)
{
	set_mutex(mtx, LOCK);
	*target = value;
	set_mutex(mtx, UNLOCK);
}

int	get_number(int *target, pthread_mutex_t *mtx)
{
	int	value;

	if (!target)
		return (-1);
	set_mutex(mtx, LOCK);
	value = *target;
	set_mutex(mtx, UNLOCK);
	return (value);
}

void	set_number(int *target, int value, pthread_mutex_t *mtx)
{
	set_mutex(mtx, LOCK);
	*target = value;
	set_mutex(mtx, UNLOCK);
}

time_t	get_lmt(t_philo *philo)
{
	time_t	val;

	set_mutex(&philo->lmt_mtx, LOCK);
	val = philo->lmt;
	set_mutex(&philo->lmt_mtx, UNLOCK);
	return (val);
}

void	set_lmt(t_philo *philo, time_t val)
{
	set_mutex(&philo->lmt_mtx, LOCK);
	philo->lmt = val;
	set_mutex(&philo->lmt_mtx, UNLOCK);
}
