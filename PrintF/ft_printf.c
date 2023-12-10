/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:32:02 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/07 16:35:04 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(char const *str, ...)
{
	int 	count;
	va_list	args;
	t_flags *flags;

	count = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_check_flags(str + 1, flags);
		}
		ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	ft_printf("Test %-010d termina\n", 10);
}