/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:41:30 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:26:45 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

static int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || s[i] == '\0')
		return (0);
	if (s[i] != c)
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_makestring(char const *s, char c)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	i = 0;
	words = ft_word_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (*s && i < words)
	{
		while (*s == c)
			s++;
		arr[i] = ft_makestring(s, c);
		if (arr[i] == NULL)
		{
			ft_free_arr(arr);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/* int	main(void)
{
	int i = 0;
	int words = ft_word_counter("lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	char **arr = ft_split("lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (i < words)
	{
		printf("String: %s\n", arr[i]);
		i++;
	}
	return (0);
} */