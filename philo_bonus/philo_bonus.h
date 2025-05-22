/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/21 13:48:22 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "./Deps/deps.h"
#include "./types.h"
#include "./includes.h"

# define FAIL -1
# define SUCCESS 0

# define UNUSED 0
# define USED 1

# define THINKING_TIME 80

void	get_data(int ac, char **av, t_program *prog);
void	initialize_program_data(t_program *prog);
time_t	get_current_time(t_program *prog);
void	launch_monitor(t_program *prog);

/*Checkers*/
bool	has_philo_starved(t_philo *philo);
void	stop_simulation(t_program *prog);
bool	is_simulation_finished(t_program *prog);
bool	are_philos_all_ready(t_program *prog);
#endif
