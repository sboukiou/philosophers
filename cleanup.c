/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:52:13 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 16:54:29 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./philo.h"

void	cleanup(t_program *program)
{
	if (!program)
	{
		print_info("Nothing to cleanup ! quitting ...");
		exit(0);
	}
	free(program);
	print_info("Cleaned up the program .");
	exit(0);

}
