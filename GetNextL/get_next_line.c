/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:10:23 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/14 18:27:34 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str)
{
	char	*buf;
	int		sz;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	sz = read(fd, buf, BUFFER_SIZE);
	if (sz == -1 || sz == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[sz] = '\0';
	str = ft_strjoin(str, buf);
	if (!str)
	{
		free(buf);
		return (NULL);
	}
	return (str);
}

char	*get_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (ft_substr(str, 0, i + 1));
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (!fd)
		return (NULL);
	if (!str)
	{
		str = "";
		str = ft_read_file(fd, str);
		if (!str)
			return (NULL);
	}
	result = get_new_line(str);
	while (!result)
	{
		str = ft_read_file(fd, str);
		if (!str)
		{
			free(str);
			return (NULL);
		}
		result = get_new_line(str);
	}
	str = ft_read_file(fd, str);
	return (result);
}

/* int	main(int argc, char **argv)
{
	int fd;
	int i;

	i = 0;
	if (argc < 2)
		get_next_line(0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		while (i < 5)
		{
			printf("%s", get_next_line(fd));
			i++;
		}
	}
	return (0);
} */