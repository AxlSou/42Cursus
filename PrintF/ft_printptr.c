/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:12:29 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 20:19:58 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(unsigned long nbr, char *base, int *count)
{
	if (nbr > ft_strlen(base) - 1)
	{
		ft_printptr(nbr / ft_strlen(base), base, count);
		ft_printchr(base[(nbr % ft_strlen(base))], count);
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		ft_printchr(base[(nbr % ft_strlen(base))], count);
	}
}
