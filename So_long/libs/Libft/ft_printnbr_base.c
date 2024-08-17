/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:06:19 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 13:02:15 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr_base(unsigned int nbr, char *base, int *count)
{
	if (nbr > ft_strlen(base) - 1)
	{
		ft_printnbr_base(nbr / ft_strlen(base), base, count);
		ft_printchr(base[(nbr % ft_strlen(base))], count);
	}
	else
		ft_printchr(base[(nbr % ft_strlen(base))], count);
}
