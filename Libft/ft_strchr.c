/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:11:10 by asoubiel          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:13 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c);

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
		{
			return ((char *)str + index);
		}
		index++;
	}
	if ((char)c == '\0')
		return ((char *)str + index);
	return (0);
}

/* int	main(void)
{
	char src[] = "ibudsvs Hola oewibvowrsd Hola";
	char dest = '\0';
	printf("%s", ft_strchr(src, dest));
	return (0);
} */