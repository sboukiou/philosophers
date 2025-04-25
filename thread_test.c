#include <pthread.h>
#include <stdio.h>

void	*routine(void *arg)
{
	(void)arg;
	pthread_join(pthread_self(), NULL);
	return (NULL);
}

int main(int ac, char *av[])
{
	pthread_t	thread_id;

	printf("Befoer Creating the thread routine\n");
	pthread_create(&thread_id, NULL, routine, NULL);
	printf("After Creating the thread routine\n");
	return (0);
}
