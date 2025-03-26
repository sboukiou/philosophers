/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:07:57 by sboukiou          #+#    #+#             */
/*   Updated: 2025/03/20 12:56:40 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	count;
pthread_mutex_t mutex;


void	*deposite(void *sum)
{
	(void)sum;
	usleep(20000);
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 400000; i++)
		count ++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}


int main(int ac, char **av)
{
	pthread_t first_thread;
	pthread_t second_thread;
	t_philo_data	*philo_data;
	int	depo1;
	int	depo2;

	pthread_mutex_init(&mutex, NULL);
	count = 0;
	depo1 = 300;
	depo2 = 200;
	philo_data = args_checker(ac, av);
	if (philo_data)
		free(philo_data);
	if (pthread_create(&first_thread, NULL, deposite, &depo1) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to create a thread\n"), -1);
	if (pthread_create(&second_thread, NULL, deposite, &depo2) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to create a thread\n"), -1);
	if (pthread_join(first_thread, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to join thread\n"), -1);
	if (pthread_join(second_thread, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to join thread\n"), -1);
	printf("Total is  %d\n", count);
	pthread_mutex_destroy(&mutex);
	return (0);
}
