/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmedin <angmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:34:46 by angmedin          #+#    #+#             */
/*   Updated: 2023/05/16 14:56:29 by angmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa_len_ptr(uintptr_t n)
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

static int	print_hexa(uintptr_t nbr)
{
    int len;

    len = hexa_len_ptr(nbr);
	if (nbr > 15)
    {
        print_hexa(nbr / 16);
        print_hexa(nbr % 16);
    }
    else if (nbr > 9 && nbr < 16)
    {
        nbr = nbr - 10 + 'a';
        write(1, &nbr, 1);
    }
    else
    {
        nbr = nbr + '0';
        write(1, &nbr, 1);
    }
    return(len);
}

int print_ptr(void *ptr)
{
    int     len;
    uintptr_t    n;

    len = 0;
    n = (uintptr_t) ptr;
    len += write(1, "0x", 2);
    len += print_hexa(n);
    return(len);
}