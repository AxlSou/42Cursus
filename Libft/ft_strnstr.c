/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:02:20 by asoubiel          #+#    #+#             */
/*   Updated: 2023/11/27 16:25:46 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		index;
	size_t	to_find_len;
	size_t	iter;

	to_find_len = ft_strlen(needle);
	index = 0;
	iter = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[index] != '\0' && len > 0)
	{
		if (haystack[index] == needle[iter])
		{
			if (iter == to_find_len - 1 || iter == len -1)
				return ((char *)&(haystack[index - iter]));
			iter++;
		}
		else
			iter = 0;
		index++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char *largestring = "Foo Bar	Baz";
	const char *smallstring = "Baz";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, 3);
	printf("Resultado: %s", ptr);
	return (0);
} */