/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:37:40 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/19 21:01:23 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

static void	check_limits(long n)
{
	if (n < -2147483648 || n > 2147483647)
		ft_error();
}

static int	check_spaces(const char c)
{
	if (c == '\t' || c == '\n' || c == ' '
		|| c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atol(const char *str)
{
	int		index;
	long	result;
	int		is_negative;

	index = 0;
	result = 0;
	is_negative = 1;
	while (check_spaces(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			is_negative *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	if (str[index] && !ft_isdigit(str[index]))
		ft_error();
	check_limits(result);
	return (result * is_negative);
}
