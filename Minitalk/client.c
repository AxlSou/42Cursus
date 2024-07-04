/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:35:06 by asoubiel          #+#    #+#             */
/*   Updated: 2024/07/04 19:37:37 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	char_to_sig(int pid, char *str)
{
	int	i;

	i = 7;
	while (*str)
	{
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(999);
			i--;
		}
		i = 7;
		str++;
	}
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(999);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (0);
	else
		char_to_sig(pid, argv[2]);
	return (0);
}
