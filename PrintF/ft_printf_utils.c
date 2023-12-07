/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:21 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/07 13:24:03 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_flags(char const *str, t_flags *flags)
{
	if (*str + 1 == '-')
		flags->ljust = 1;
	else if (*str + 1 == '0')
		ft_zero_flag(str, flags); // To check
	else if (*str + 1 == '.')
		ft_precision_flag(str, flags); // To check
	else if (*str + 1 == '#')
		ft_hashtag_flag(str); // To check
	else if (*str + 1 == ' ')
		ft_putchar_fd(' ', 1);
	else if (*str + 1 == '+')
		flags->plus = 1;
}
