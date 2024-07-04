/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:35:10 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/29 16:24:46 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

static void	print_str(void)
{
	int	val;
	int	i;
	int	result;

	i = 0;
	val = 128;
	result = 0;
	if (ft_strlen(g_str) % 8 != 0)
		return ;
	else
	{
		while (g_str[i])
		{
			if (g_str[i] == '1')
				result += val;
			i++;
			val /= 2;
		}
		ft_printf("%c", result);
		if (result == 0)
			ft_printf("\n");
	}
	free(g_str);
	g_str = NULL;
}

static void	sig_to_str(char **str, char *sig)
{
	char	*tmp;

	tmp = *str;
	if (!str || !*str)
		*str = ft_strdup(sig);
	else
	{
		*str = ft_strjoin(*str, sig);
		free(tmp);
	}
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		sig_to_str(&g_str, "1");
	else if (sig == SIGUSR2)
		sig_to_str(&g_str, "0");
	else if (sig == SIGINT)
	{
		if (g_str)
			free(g_str);
		exit(0);
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_handler = &sig_handler;
	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		sigaction_error();
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		sigaction_error();
	if (sigaction(SIGINT, &act, NULL) == -1)
		sigaction_error();
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
		print_str();
	}
	return (0);
}
