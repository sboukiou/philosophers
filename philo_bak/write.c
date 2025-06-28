# include "./philo.h"


int	write_status(const char *status, int id, t_prog *prog)
{
	time_t	now;

	now = get_current_time(prog);
	set_mutex(&prog->write_mtx, LOCK);
	printf("[%8lu] %d %s\n"RESET, now, id, status);
	set_mutex(&prog->write_mtx, UNLOCK);
	return (0);
}
