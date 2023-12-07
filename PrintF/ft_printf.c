/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:32:02 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/07 13:24:16 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;
	t_flags	*flags;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_check_flags(str, flags);
		}
		ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	printf("%- d", 10);
}