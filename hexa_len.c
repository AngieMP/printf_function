#include "ft_printf.h"

int	hexa_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}