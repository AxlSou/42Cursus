/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:21:11 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:28:00 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char)c)
		{
			return ((char *)s + index);
		}
		index--;
	}
	return (NULL);
}

/* int	main(void)
{
	const char str[] = "https://www.tutorialspoint.com";
	const char ch = 't';
	char *ret;

	ret = ft_strrchr(str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);

	return (0);
} */