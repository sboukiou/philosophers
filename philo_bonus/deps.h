#ifndef DEPS_H
# define DEPS_H

#include <stddef.h>
#include <stdlib.h>

# define MARK(str) \
	printf("[%s](%d)  [%s]\n", __FILE__, __LINE__, str);\

char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
# endif /* DEPS_H */
