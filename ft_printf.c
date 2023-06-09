/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmedin <angmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:34:46 by angmedin          #+#    #+#             */
/*   Updated: 2023/05/19 13:10:54 by angmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check(char x, va_list args, ...)
{
    if(x == 'c')
        return(print_char(va_arg(args, int)));
	else if(x == '%')
        return(write(1, &x, 1));
    else if(x == 's')
        return(print_str(va_arg(args, char*)));
    else if(x == 'p')
        return(print_ptr(va_arg(args, void*)));
    else if(x == 'd' || x == 'i')
        return(print_nbr(va_arg(args, int)));
	else if(x == 'u')
		return(print_unsigned(va_arg(args, unsigned int)));
    else if(x == 'x')
		return(print_low_hexa(va_arg(args, unsigned int)));
	else if(x == 'X')
		return(print_upp_hexa(va_arg(args, unsigned int)));
	else
		return(0);
}
int	ft_printf(char const *str, ...)
{
	int	i;
    int len;

	i = 0;
    len = 0;
	va_list args;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == 32)
				i++;
			len += check(str[i], args);
			i++;
		}
		else
		{
			len += print_char(str[i]);
			i++;
		}
	}
    return(len);
}

#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	lhexa = 0;
	int	uhexa = 23456789;
	char			c = 's';
	char			*arr = "manolo";
	int				x = 567;
	unsigned int uint = 4567890;
	void	*ptr = "hola";

	ft_printf("Mi función dice que ha escrito %d bytes\n", ft_printf("mi string es %s, mi char es %c, mi unsigned es %u, mi uhexa es %X y mi lhexa %x, mi int es %d y tambien %i\n", arr, c, uint, uhexa, lhexa, x, x));
	printf("La función original dice que ha escrito %d bytes\n", printf("mi string es %s, mi char es %c, mi unsigned es %u, mi uhexa es %X y mi lhexa %x, mi int es %d y tambien %i\n", arr, c, uint, uhexa, lhexa, x, x));

	ft_printf("Mi función para ptr escribe %d bytes \n", ft_printf("Mi puntero es %p", ptr));
	printf("Mi función para ptr escribe %d bytes \n", printf("Mi puntero es %p", ptr));
}