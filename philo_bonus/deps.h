/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:38:15 by sboukiou          #+#    #+#             */
/*   Updated: 2025/07/08 18:38:31 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPS_H
# define DEPS_H

# include <stddef.h>
# include <stdlib.h>

char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
#endif /* DEPS_H */
