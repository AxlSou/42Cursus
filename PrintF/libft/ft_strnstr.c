/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:02:20 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:27:54 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	to_find_len;
	size_t	iter;

	to_find_len = ft_strlen(needle);
	index = 0;
	iter = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[index] != '\0' && index < len)
	{
		iter = 0;
		while (needle[iter] != '\0' && needle[iter] == haystack[index + iter]
			&& index + iter < len)
			iter++;
		if (needle[iter] == '\0')
			return ((char *)haystack + index);
		index++;
	}
	return (NULL);
}

/* int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("Original: %s\n", strnstr(haystack, "abcd", 9));
	printf("Resultado: %s\n", ft_strnstr(haystack, "abcd", 9));
	return (0);
} */