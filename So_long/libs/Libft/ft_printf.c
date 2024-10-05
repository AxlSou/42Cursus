/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:32:02 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 21:02:16 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			str = ft_print_arg(str + 1, args, &count);
		if (*str && *str != '%')
		{
			ft_printchr(*str, &count);
			str++;
		}
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	printf("\nPrintf: %d\n", ft_printf("% d", 10));
	printf("\nPrintf: %d\n", printf("% d", 10));
} */
