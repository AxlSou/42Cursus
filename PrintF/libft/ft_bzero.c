/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:48:05 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/05 11:23:55 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/* int	main(void)
{
	char str[] = "This is string.h library function";
	printf("Original: %s\n", str);

	ft_bzero(str, 7);
	printf("Nueva: %s", str);

	return (0);
} */