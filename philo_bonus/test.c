#include "./philo.h"
#include <sys/time.h>

void	custom_usleep(int time)
{
	struct timeval	tv_start;
	struct timeval	tv_end;
	struct timezone	tz_start;
	struct timezone	tz_end;

	gettimeofday(&tv_start, &tz_start);
	gettimeofday(&tv_end, &tz_end);
	while (tv_end.tv_usec < tv_start.tv_usec + time * 1000)
		gettimeofday(&tv_end, &tz_end);

}

int main(void)
{
	struct timeval	tv_start;
	struct timeval	tv_end;
	struct timezone	tz_start;
	struct timezone	tz_end;
	int time_requested_usleep = 30;

	gettimeofday(&tv_start, &tz_start);
	custom_usleep(time_requested_usleep);
	// usleep(time_requested_usleep);
	gettimeofday(&tv_end, &tz_end);
	printf("%lld -> %lld\n", (long long)(tv_start.tv_usec), (long long)(tv_end.tv_usec));
	printf("usleep() time requested -> %d\n", time_requested_usleep);
	printf("Actual time spent -> %lld\n", (long long)(tv_end.tv_usec - tv_start.tv_usec) / 1000);
	return (0);
}
