/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:40:46 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/08 18:40:47 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deps.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = malloc(s1_len + s2_len + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, s1, s1_len + 1);
	ft_strlcat(buff, s2, s1_len + s2_len + 1);
	return (buff);
}
