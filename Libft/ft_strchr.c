/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:20:35 by asoubiel          #+#    #+#             */
/*   Updated: 2023/10/31 16:20:35 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *str, int c);

char *ft_strchr(const char *str, int c)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
		{
			return ((char *)&str[index]);
		}
		index++;
	}
	return (0);
}
/*
int main()
{
	char src[] = "ibudsvs Hola oewibvowrsd Hola";
	char dest = 'H';
	printf("%s", ft_strchr(src, dest));
	return (0);
} */
