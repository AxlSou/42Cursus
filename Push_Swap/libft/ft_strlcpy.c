/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:55:02 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/01 11:28:21 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (index < dstsize - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

/* int	main(void)
{
	char str1[] = "C Programming";
	char str2[] = "osaivaoievao";

	printf("La primera string es: %s, y la segunda es: %s \n", str1, str2);
	//printf("%lu\n", strlcpy(str2, str1, 0));
	printf("%zu\n", ft_strlcpy(str2, str1, 5));
	printf("La primera string es: %s, y la segunda es: %s \n", str1, str2);
} */