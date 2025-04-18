/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:30:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/04/16 18:40:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./deps.h"

#define RESET "\033[0m"
#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"

void	print_error(char *error)
{
	write(STDERR_FILENO, BRED, _strlen(BRED));
	write(STDERR_FILENO, "[ERROR]: ", 10);
	write(STDERR_FILENO, error, _strlen(error));
	write(STDERR_FILENO, " \n", 3);
	write(STDERR_FILENO, RESET, _strlen(RESET));
}

void	print_info(char *info)
{
	write(STDOUT_FILENO, BYELLOW, _strlen(BYELLOW));
	write(STDOUT_FILENO, "[INFO]: ", 9);
	write(STDOUT_FILENO, info, _strlen(info));
	write(STDOUT_FILENO, " \n", 3);
	write(STDOUT_FILENO, RESET, _strlen(RESET));
}
