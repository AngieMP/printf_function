#include "ft_printf.h"

int print_char(char a)
{
    return(write(1, &a, 1));
}