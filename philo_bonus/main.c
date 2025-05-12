/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:09:48 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/12 11:18:00 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int main(int ac, char **av)
{
	t_program	*prog;
	prog = parser(ac, av);
	if (!prog)
		return (0);
	if (init(prog) != SUCCESS)
		return (0);
	start_dinner(prog);
}
