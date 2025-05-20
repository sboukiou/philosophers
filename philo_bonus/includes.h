/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:49:19 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/19 09:07:52 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h> /* For printf */
# include <pthread.h> /* For posix threads | creation, monitor, join, mutexs, lock & unlock*/
# include <stdlib.h> /* For malloc, Free */
# include <stdbool.h> /* For true, false */
# include <unistd.h> /* For write, usleep */
# include <fcntl.h> /* For files macros */
# include <limits.h> /* INT_MIN & INT_MAX */
# include <sys/time.h> /* For gettimeofday & settimeofday */
# include <string.h> /* For memset */
# include <semaphore.h> /* For sem_t and its functions */
# include <sys/wait.h> /* For processes */
# include <sys/types.h> /* same */
  
# define RESET "\033[0m"
# define BRED "\033[1;31m"
# define BACKGROUND_RED "\e[41m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define UPURPLE "\e[4;35m"

#endif
