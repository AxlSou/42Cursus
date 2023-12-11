/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:21 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/11 12:38:49 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char *ft_zero_flag(char const *str, t_flags *flags)
{
	flags->zero = 1;
	while (ft_isdigit(*str))
	{
		flags->width += *str - '0';
		flags->width *= 10;
		str++;
	}
	flags->width /= 10;
	
	return ((char *)str - 1);
}

static char *ft_precision_flag(char const *str, t_flags *flags)
{
	flags->prec = 0;
	while (ft_isdigit(*str))
	{
		flags->prec+= *str - '0';
		flags->prec *= 10;
		str++;
	}
	return ((char *)str);
}

char	*ft_check_flags(char const *str, t_flags *flags)
{
	while (!ft_isinset("cspdiuxX%", *str))
	{
		if (*str == '-')
			flags->ljust = 1;
		else if (*str == '0')
			str = ft_zero_flag(str, flags);
		else if (*str == '.')
			ft_precision_flag(str, flags);
		else if (*str == '#')
			flags->hasht = 1;
		else if (*str == ' ')
			ft_putchar_fd(' ', 1);
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == '%')
			ft_putchar_fd('%', 1);
		str++;
	}
/* 	printf("Length: %d\n", flags->width);
	printf("Prec: %d\n", flags->prec);
	printf("Ljust: %d\n", flags->ljust);
	printf("Plus: %d\n", flags->plus);
	printf("Hasht: %d\n", flags->hasht);
	printf("Zero: %d\n", flags->zero); */
	return ((char *)str);
}
