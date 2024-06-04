/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:37:40 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 20:19:43 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"	

/* static void	check_limits(long n)
{
	if (n < -2147483648 || n > 2147483647)
		error();
} */

/* int	ft_atoi(const char *str)
{
	int		index;
	long	result;
	int		is_negative;

	index = 0;
	result = 0;
	is_negative = 1;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == ' '
		|| str[index] == '\f' || str[index] == '\v' || str[index] == '\r')
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
	check_limits(result);
	return (result * is_negative);
} */