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

int	print_upp_hexa(unsigned int nbr)
{
    int len;

    len = hexa_len(nbr);
	if (nbr > 15)
    {
        print_upp_hexa(nbr / 16);
        print_upp_hexa(nbr % 16);
    }
    else if (nbr > 9 && nbr < 16)
    {
        nbr = nbr - 10 + 'A';
        write(1, &nbr, 1);
    }
    else
    {
        nbr = nbr + 48;
        write(1, &nbr, 1);
    }
    return(len);
}
