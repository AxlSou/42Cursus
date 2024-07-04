/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:08:05 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/12 17:09:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *str, int *count)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar_fd(*str, 1);
		str++;
		*count += 1;
	}
}
