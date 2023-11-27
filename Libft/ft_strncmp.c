/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:28 by asoubiel          #+#    #+#             */
/*   Updated: 2023/10/31 16:05:28 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n);

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	index;

	index = 0;
	while ((str1[index] != '\0' || str2[index] != '\0') && index < n)
	{
		if (str1[index] > str2[index])
		{
			return (1);
		}
		else if (str1[index] < str2[index])
		{
			return (-1);
		}
		index++;
	}
	return (0);
}
/* int main(void)
{
	char	str1[] = "Haorla1";
	char	str2[] = "Hola2";
	char	str3[] = "Haola3";

	printf("%i\n", ft_strncmp(str1, str2, 2));
	printf("%i", ft_strncmp(str3, str1, 2));
	return (0);
} */
