/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:24:42 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/11 11:08:43 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	width;
	int	prec;
	int	ljust;
	int	plus;
	int	hasht;
	int	zero;
}		t_flags;

int		ft_printf(char const *str, ...);
char	*ft_check_flags(char const *str, t_flags *flags);
char	*ft_print_arg(char const *str, t_flags *flags, va_list args, int *count);

#endif