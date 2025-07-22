/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:35:01 by codespace         #+#    #+#             */
/*   Updated: 2025/07/23 01:18:13 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int		g_string_size;

char	bin_to_char(int signum)
{
	static char	c;
	static int	i;
	char		completed_char;

	if (signum == SIGUSR1)
		c |= (1 << (7 - i));
	else if (signum == SIGUSR2)
		c &= ~(1 << (7 - i));
	i++;
	if (i == 8)
	{
		completed_char = c;
		c = 0;
		i = 0;
		return (completed_char);
	}
	return (-1);
}

void	string_checker(char *string)
{
	if (!string)
		exit(EXIT_FAILURE);
}

void	creating_string(char temp)
{
	static char	*string;
	static int	string_length;

	if (string == NULL)
	{
		string = (char *)malloc(sizeof(char) * g_string_size);
		string_checker(string);
	}
	else if (string_length + 1 >= g_string_size)
	{
		g_string_size *= MULTIPLIER;
		string = (char *)ft_realloc(string, g_string_size);
		string_checker(string);
	}
	string[string_length++] = temp;
	string[string_length] = '\0';
	if (temp == '\0')
	{
		ft_printf("String received: %s\n", string);
		free(string);
		string = NULL;
		g_string_size = 10;
		string_length = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	char		temp;
	static int	counter;

	(void)context;
	pid = info->si_pid;
	counter++;
	temp = bin_to_char(signum);
	if (counter % 8 == 0)
		creating_string(temp);
	if (!temp)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Error, server does not need an input", 2);
		exit(EXIT_FAILURE);
	}
	ft_printf("Hi, this is Márton's server!'\n");
	ft_printf("Server PID: %d\n", getpid());
	g_string_size = 10;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
