
#include "../inc/push.h"
			
size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s[i])
		while (s[i])
			i++;
	return (i);
}