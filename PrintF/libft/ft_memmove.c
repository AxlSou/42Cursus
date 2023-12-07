/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:50 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:25:42 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dst;
	csrc = (char *)src;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (len--)
		{
			*cdest++ = *csrc++;
		}
	}
	else if (dst > src)
	{
		cdest += len -1;
		csrc += len -1;
		while (len--)
		{
			*cdest-- = *csrc--;
		}
	}
	return (dst);
}

/* int main () {
   char str[] = "oldstring";

   printf("Before memmove str = %s\n", str);
   ft_memmove(str, str + 4, 5);
   //memmove(str, str + 4, 5);
   printf("After memmove str = %s\n", str);

   return(0);
} */