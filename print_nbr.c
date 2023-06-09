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

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_nbr(int n)
{
	int	len;

	len = ft_intlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		print_nbr(-n);
	}
	else
	{
		if (n > 9)
			print_nbr(n / 10);
		n = n % 10 + 48;
		write(1, &n, 1);
	}
	return (len);
}