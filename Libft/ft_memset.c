/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:35 by asoubiel          #+#    #+#             */
/*   Updated: 2023/11/27 16:45:48 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n);

void	*ft_memset(void *str, int c, size_t n)
{
	while (*(char *)str && n > 0)
	{
		*(char *)str = c;
		str++;
		n--;
	}
	return (str);
}

/* int	main(void)
{
	char str[] = "This is string.h library function";
	printf("Original: %s\n", str);

	ft_memset(str, '$', 7);
	printf("Nueva: %s", str);

	return (0);
} */