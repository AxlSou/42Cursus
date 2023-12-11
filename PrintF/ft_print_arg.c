/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:04:35 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/11 21:14:01 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printchr(int c, int *count)
{
    ft_putchar_fd(c, 1);
    *count += 1;
}

void    ft_printstr(va_list args, t_flags *flags, int *count)
{
    char *str = va_arg(args, char *);
    while (*str)
    {
        ft_putchar_fd(*str, 1);
        str++;
        *count += 1;
    }
}

int	ft_print_nbr_base(unsigned int nbr, char *base, int *count)
{	
	if (nbr > ft_strlen(base) - 1)
	{
		ft_print_nbr_base(nbr / ft_strlen(base), base, count);
		ft_printchr(base[(nbr % ft_strlen(base))], count);
	}
	else
		ft_printchr(base[(nbr % ft_strlen(base))], count);
}

int	ft_print_nbr(int nbr, int *count)
{	
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		ft_printchr('-', count);
		ft_print_nbr(nbr * -1, count);
	}
	else if (nbr > 9)
	{
		ft_print_nbr(nbr / 10, count);
		ft_printchr(nbr % 10 + '0', count);
	}
	else
		ft_printchr(nbr + '0', count);
}

char	*ft_print_arg(char const *str, t_flags *flags, va_list args, int *count)
{
	if (*str == 'c')
        ft_printchr(va_arg(args, int), count);
    else if (*str == 's')
        ft_printstr(args, flags, count);
    //else if (*str == 'p')  
    else if (*str == 'd' || *str == 'i')
        ft_print_nbr(va_arg(args, int), count);
    else if (*str == 'u')
		ft_print_nbr_base(va_arg(args, unsigned int), "0123456789", count);
    else if (*str == 'x')
		ft_print_nbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
    else if (*str == 'X')
		ft_print_nbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
    else if (*str == '%')
		ft_printchr('%', count);
    return ((char *)str + 1);
}