/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:57:18 by asoubiel          #+#    #+#             */
/*   Updated: 2023/10/31 15:57:18 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return(c);
}
/*
int main(void)
{
	printf("%d", ft_tolower('9'));
	return(0);
} */
