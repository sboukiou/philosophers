/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:49:19 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/12 11:09:40 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h> /* For printf */
# include <pthread.h> /* For posix threads | creation, monitor, join, mutexs, lock & unlock*/
# include <stdlib.h> /* For malloc, Free */
# include <stdbool.h> /* For true, false */
# include <unistd.h> /* For write, usleep */
# include <limits.h> /* INT_MIN & INT_MAX */
#include <sys/time.h> /* For gettimeofday & settimeofday */
#include <string.h> /* For memset */

# define FAIL -1
# define SUCCESS 0

#endif
