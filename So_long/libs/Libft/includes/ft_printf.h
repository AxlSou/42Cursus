/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:24:42 by asoubiel          #+#    #+#             */
/*   Updated: 2024/10/01 18:53:09 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft.h"
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
char	*ft_print_arg(char const *str, va_list args, int *count);
void	ft_printnbr(int nbr, int *count);
void	ft_printnbr_base(unsigned int nbr, char *base, int *count);
void	ft_printstr(char *str, int *count);
void	ft_printchr(int c, int *count);
void	ft_printptr(unsigned long nbr, char *base, int *count);

#endif
