/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:16:08 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/21 13:03:36 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *buf, char *str)
{
	char	*tmp;
	int		size;

	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		else if (size == 0)
			return (str);
		buf[size] = '\0';
		if (!str)
		{
			str = ft_strjoin(str, "");
			if (!str)
				return (NULL);
		}
		tmp = str;
		str = ft_strjoin(tmp, buf);
		tmp = ft_free(tmp);
		if (ft_strchr(buf, '\n'))
			return (str);
	}
	return (str);
}

char	*get_new_line(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (NULL);
	result = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*result == 0)
		result = ft_free(result);
	str[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*str[1000];
	char		*result;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	result = ft_read_file(fd, buf, str[fd]);
	buf = ft_free(buf);
	if (!result)
	{
		str[fd] = ft_free(str[fd]);
		return (NULL);
	}
	str[fd] = get_new_line(result);
	return (result);
}
