# include "./philo.h"

time_t	get_current_time(t_prog *prog)
{
	struct timeval	tv;
	struct timezone	tz;
	time_t	current_time;
	if (gettimeofday(&tv, &tz) != SUCCESS)
	{
		printf(BRED"Failed to fetch current time (gettimeofday)"RESET);
		return (FAIL);
	}
	current_time = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (current_time - get_time(&prog->start, &prog->start_mtx));
}


int	write_status(const char *status, int id, t_prog *prog)
{
	time_t	now;

	now = get_current_time(prog);
	set_mutex(&prog->write_mtx, LOCK);
	printf(BGREEN"[%8lu] %d %s\n"RESET, now, id, status);
	set_mutex(&prog->write_mtx, UNLOCK);
	return (0);
}
