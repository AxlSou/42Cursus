/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:36:16 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:25:31 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*char_str1;
	unsigned char	*char_str2;

	char_str1 = (unsigned char *)str1;
	char_str2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*char_str1 != *char_str2)
		{
			return (*char_str1 - *char_str2);
		}
		char_str1++;
		char_str2++;
		n--;
	}
	return (0);
}

/* int	main(void)
{
	char str1[] = "Hola, buenos dias";
	char str2[] = "Hola, Buenos dias";
	int result;

	result = ft_memcmp(str1, str2, 10);

	printf("Result: %i", result);
	return (0);
} */