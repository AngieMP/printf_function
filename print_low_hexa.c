/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmedin <angmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:28:35 by angmedin          #+#    #+#             */
/*   Updated: 2023/05/19 13:48:44 by angmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_low_hexa(unsigned int nbr)
{
    int len;

    len = hexa_len(nbr);
	if (nbr > 15)
    {
        print_low_hexa(nbr / 16);
        print_low_hexa(nbr % 16);
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
