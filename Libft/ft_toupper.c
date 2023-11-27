/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:52:56 by asoubiel          #+#    #+#             */
/*   Updated: 2023/10/31 15:52:56 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c);

int	ft_toupper(int c)
{
	if(c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return(c);
}
/*
int main(void)
{
	printf("%d", ft_toupper('9'));
	return(0);
} */
