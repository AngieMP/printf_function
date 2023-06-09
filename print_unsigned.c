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

int print_unsigned(unsigned int n)
{
    static int len = 0;

    if (n > 9)
        print_unsigned(n/10);
    n = (n % 10) + 48;
    len += write(1, &n, 1);
    return(len);
}