/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:19 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 19:38:16 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	index;
	int	result;
	int	is_negative;

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
	return (result * is_negative);
}

/* 
int	main(void)
{
	printf("%i\n", ft_atoi("			-2147483648"));
	printf("%i", atoi("			 -45689 ed 16560"));
	return (0);
} */