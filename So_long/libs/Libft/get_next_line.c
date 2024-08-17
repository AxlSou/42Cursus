/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:10:23 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/17 20:37:32 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_file(int fd, char *buf, char *str)
{
	char *tmp;
	int size;

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
			str = ft_strjoin_gnl(str, "");
			if (!str)
				return (NULL);
		}
		tmp = str;
		str = ft_strjoin_gnl(tmp, buf);
		tmp = ft_free_gnl(tmp);
		if (ft_strchr_gnl(buf, '\n'))
			return (str);
	}
	return (str);
}

char *get_new_line(char *str)
{
	char *result;
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (NULL);
	result = ft_substr_gnl(str, i + 1, ft_strlen_gnl(str) - i);
	if (*result == 0)
		result = ft_free_gnl(result);
	str[i + 1] = '\0';
	return (result);
}

char *get_next_line(int fd)
{
	static char *str;
	char *result;
	char *buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	result = ft_read_file(fd, buf, str);
	buf = ft_free_gnl(buf);
	if (!result)
	{
		str = ft_free_gnl(str);
		return (NULL);
	}
	str = get_new_line(result);
	return (result);
}

/* int	main(int argc, char **argv)
{
	int fd;
	int i;
	char	*line;
	i = 0;

	if (argc < 2)
		get_next_line(0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		while (i < 13)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
			i++;
		}
	}
	return (0);
}  */
