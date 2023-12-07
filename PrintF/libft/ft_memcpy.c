/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:12:16 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:25:35 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* int	main(void)
{
	const char src[] = "perro";
	char dest[] = "casa";

	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, 5);
	printf("After memcpy dest = %s\n", dest);

	return (0);
} */