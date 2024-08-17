/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:05:04 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 13:02:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr(int nbr, int *count)
{
	if (nbr == -2147483648)
		ft_printstr("-2147483648", count);
	else if (nbr < 0)
	{
		ft_printchr('-', count);
		ft_printnbr(nbr * -1, count);
	}
	else if (nbr > 9)
	{
		ft_printnbr(nbr / 10, count);
		ft_printchr(nbr % 10 + '0', count);
	}
	else
		ft_printchr(nbr + '0', count);
}
