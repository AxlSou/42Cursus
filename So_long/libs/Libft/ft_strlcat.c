/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:43:54 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/04 13:31:36 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_src;
	size_t	index_dest;

	index_src = 0;
	index_dest = ft_strlen(dst);
	if (dstsize < index_dest || dstsize == 0)
		return (dstsize + ft_strlen(src));
	while (src[index_src] != '\0' && index_dest < dstsize - 1)
	{
		dst[index_dest] = src[index_src];
		index_src++;
		index_dest++;
	}
	dst[index_dest] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[index_src]));
}

/* int	main(void)
{
	char src[] = "testing";
	char dest[20];
	//printf("Original:%lu\n", strlcat(dest, "123", 0));
	printf("Duplicate: %lu\n", ft_strlcat(dest, "123", 0));
	printf("%s \n", dest);
	printf("%s", src);
	return (0);
} */