/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:32:42 by asoubiel          #+#    #+#             */
/*   Updated: 2023/10/31 12:32:42 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFT_H
# define LIBFT_H
# include <stdio.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int	ft_toupper(int c);
int	ft_tolower(int c);
char *ft_strchr(const char *str, int c);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int	ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
