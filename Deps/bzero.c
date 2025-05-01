/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:11:18 by sboukiou          #+#    #+#             */
/*   Updated: 2025/05/01 17:13:23 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"

void	_bzero(void *addr, size_t size)
{
	char	*iterator;
	size_t	count;

	if (!addr)
		return ;
	count = 0;
	iterator = (char *)addr;
	while (count < size)
	{
		iterator[count] = '\0' ;
		count++;
	}
}
