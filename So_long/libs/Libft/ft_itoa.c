/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:48:00 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:59 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);

static int	ft_check_len(int n)
{
	int		len;
	int		n_cpy;

	n_cpy = n;
	len = 0;
	if (n_cpy < 0)
	{
		len++;
		n_cpy *= -1;
	}
	while (n_cpy > 0)
	{
		len++;
		n_cpy /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*arr;

	len = ft_check_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	arr[len] = '\0';
	len--;
	while (n > 0)
	{
		arr[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (arr);
}

/* int	main(void)
{
	printf("Resultado: %s", ft_itoa(-13168168));
	return (0);
} */