/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:10:26 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/18 18:57:28 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*new_dst;
	char	*new_src;

	new_dst = (char *)dst;
	new_src = (char *)src;
	if (!new_dst && !new_src)
		return (NULL);
	while (n > 0)
	{
		*new_dst = *new_src;
		new_src++;
		new_dst++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len + 1);
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, &s[start], len);
	substr[len] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1_len && !s2_len)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}
