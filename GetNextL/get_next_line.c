/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:10:23 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/19 00:15:01 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str, int *sz)
{
	char	*buf;
	char	*new_str;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf || !str)
		return (NULL);
	*sz = read(fd, buf, BUFFER_SIZE);
	if (*sz < 1)
	{
		free(buf);
		if (*sz == 0)
			return (str);
		else
			return (NULL);
	}
	buf[*sz] = '\0';
	new_str = ft_strjoin(str, buf);
	if (!new_str)
		return (NULL);
	free(buf);
	free(str);
	str = new_str;
	return (str);
}

char	*get_new_line(char *str, int *sz)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (*sz == 0)
		return (ft_substr(str, 0, ft_strlen(str) + 1));
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
	int			sz;

	sz = 0;
	if (!fd)
		return (NULL);
	if (!str || *str == 0)
	{
		str = ft_strdup("");
		str = ft_read_file(fd, str, &sz);
		if (!str || *str == 0)
			return (NULL);
	}
	result = get_new_line(str, &sz);
	while (!result)
	{
		str = ft_read_file(fd, str, &sz);
		result = get_new_line(str, &sz);
	}
	str = NULL;
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
		while (i < 2)
		{
			printf("%s", get_next_line(fd));
			i++;
		}
	}
	return (0);
} */