/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:07:57 by sboukiou          #+#    #+#             */
/*   Updated: 2025/03/17 08:54:25 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FAIL -1
# define SUCCESS 0
#include "./philosophers.h"

int	check_args(int ac, char **av)
{
	int	count;

	if (ac < 4)
		return (printf("Number of arguments invalid\n"), FAIL);
	count = 0;
	while (av[count])
	{
		printf("Arg N%d -> %s\n", count, av[count]);
		count++;
	}
	return (SUCCESS);
}


void	*first_thread_test_printer(void *data)
{
	(void)data;
	printf("Hello from the first thread printer\n");
	sleep(2);
	return (NULL);
}


void	*second_thread_test_printer(void *data)
{
	(void)data;
	printf("Hello from the second thread printer\n");
	sleep(2);
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t first_thread;
	pthread_t second_thread;

	(void)ac;
	(void)av;
	if (pthread_create(&first_thread, NULL, first_thread_test_printer, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to create a thread\n"), -1);
	if (pthread_create(&second_thread, NULL, second_thread_test_printer, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to create a thread\n"), -1);
	if (pthread_join(first_thread, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to join thread\n"), -1);
	if (pthread_join(second_thread, NULL) != 0)
		return (dprintf(STDERR_FILENO, "[ERROR]: Failed to join thread\n"), -1);
	return (0);
}
