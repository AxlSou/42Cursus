/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:17:54 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/21 12:18:03 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;
	size_t	i;

	i = 0;
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strjoin("", ""));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[start++];
	substr[len] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;

	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!result)
		return (NULL);
	while (i < s1_len)
		result[i++] = *s1++;
	while (i < s1_len + s2_len)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
