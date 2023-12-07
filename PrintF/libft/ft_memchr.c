/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:04:30 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:25:26 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*char_ptr;

	i = 0;
	char_ptr = (unsigned char *)str;
	while (i < n)
	{
		if (*char_ptr == (unsigned char)c)
		{
			return ((void *)char_ptr);
		}
		char_ptr++;
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	const char str[] = "https:www.google.com";
	const char ch = '.';
	char *ret;

	ret = ft_memchr(str, ch, 15);

	printf("String after |%c| is - |%s|\n", ch, ret);

	return (0);
} */