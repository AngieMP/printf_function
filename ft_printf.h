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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int ft_printf(char const *str, ...);
int print_char(char a);
int print_str(char *str);
int print_nbr(int n);
int print_low_hexa(unsigned int nbr);
int print_upp_hexa(unsigned int nbr);
int ft_strlen(char *str);
int print_unsigned(unsigned int n);
int print_ptr(void *ptr);
int hexa_len(unsigned int n);

#endif