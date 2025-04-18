/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:21:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/18 16:54:07 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
#include "./Deps/deps.h"

int main(int ac, char **av)
{
	t_program	*program;

	program = parser(ac, av);
	// init(program);
	// simulate_dinner(program);
	cleanup(program);
	return (0);
}
