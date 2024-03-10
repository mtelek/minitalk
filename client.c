/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:10:34 by codespace         #+#    #+#             */
/*   Updated: 2024/03/10 15:38:15 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	terminator_strikes_back(char terminator, int pid)
{
	static int	i;

	if (terminator & (1 << (7 - i)))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	i++;
}

void	char_to_bin(char *message, int pid)
{
	static int	i;
	static char	*string;
	static int	j;
	char		terminator;

	terminator = '\0';
	if (string == NULL)
		string = message;
	if (string[j])
	{
		if (string[j] & (1 << (7 - i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
	else
		terminator_strikes_back(terminator, pid);
	if (i == 8)
	{
		j++;
		i = 0;
	}
	usleep(100);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	counter;
	static int	bytes_received;

	(void)context;
	pid = info->si_pid;
	if (signum == SIGUSR2)
	{
		bytes_received++;
		ft_printf("Number of bytes sent: %d\n", bytes_received);
		exit(EXIT_FAILURE);
	}
	else if (signum == SIGUSR1)
	{
		counter++;
		if (counter % 8 == 0)
		{
			bytes_received++;
			ft_printf("Number of bytes sent: %d\n", bytes_received);
		}
		char_to_bin(NULL, pid);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	argc_checker(argc, argv);
	pid = atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	char_to_bin(argv[2], pid);
	while (1)
		pause();
	return (0);
}