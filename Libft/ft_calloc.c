/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:07:09 by asoubiel          #+#    #+#             */
/*   Updated: 2023/11/29 21:56:53 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/* int	main(void)
{
	int n;
	char *a;

	n = 10;

	a = (char *)calloc(n, sizeof(char));
	
	while(n > 0)
	{
		a[n -1] = 'H';
		n--;
	}
	printf("Resultado: %s", a);
	free(a);
	
	return(0);
} */