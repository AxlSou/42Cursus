/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:04:35 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 19:59:30 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_arg(char const *str, va_list args, int *count)
{
	if (*str == 'c')
		ft_printchr(va_arg(args, int), count);
	else if (*str == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (*str == 'p')
		ft_printptr((unsigned long)va_arg(args, void *), "0123456789abcdef",
			count);
	else if (*str == 'd' || *str == 'i')
		ft_printnbr(va_arg(args, int), count);
	else if (*str == 'u')
		ft_printnbr_base(va_arg(args, unsigned int), "0123456789", count);
	else if (*str == 'x')
		ft_printnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (*str == 'X')
		ft_printnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (*str == '%')
		ft_printchr('%', count);
	return ((char *)str + 1);
}
