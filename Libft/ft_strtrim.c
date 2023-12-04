/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:52:02 by asoubiel          #+#    #+#             */
/*   Updated: 2023/11/30 17:34:46 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set);

static int	ft_isinset(char const *set, char c);

static int	ft_isinset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while (s1[i] && ft_isinset(set, s1[i]) == 1)
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_isinset(set, s1[i]) == 1)
		i--;
	end = i;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, (end - start) + 1));
}

/* int	main(void)
{
	printf("Resultado: %s\n",
		ft_strtrim("xxxz  test with x and z and x .  zx  xx z", "z x"));
	return (0);
} */