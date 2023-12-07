/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:35 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:25:49 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*cstr;

	cstr = (char *)str;
	i = 0;
	while (n > 0)
	{
		cstr[i] = c;
		i++;
		n--;
	}
	return (str);
}

/* int	main(void)
{
	char str[] = "jjjjjjjjjjjjjjj";
	char str2[] = "jjjjjjjjjjjjjjj";
	printf("Original: %s\n", str);
	memset(str, 'c', 5);
	printf("Original: %s\n", str);
	printf("Nueva: %s\n", str2);
	ft_memset(str2, 'c', 5);
	printf("Nueva: %s", str2);

	return (0);
} */