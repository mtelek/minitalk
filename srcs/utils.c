/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:55:06 by codespace         #+#    #+#             */
/*   Updated: 2025/07/23 00:08:32 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;
	size_t	i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (0);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	i = 0;
	while (((char *)ptr)[i] != '\0')
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

int	pid_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				ft_putendl_fd("Error, not valid PID", 2);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	return (0);
}

int	argc_checker(int argc, char **argv)
{
	if (argc == 2 || argc == 1)
	{
		ft_putendl_fd("Error, nothing to send", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		ft_putendl_fd("Error, too many arguments", 2);
		exit(EXIT_FAILURE);
	}
	else
		pid_checker(argc, argv);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	parity;
	int	num;
	int	i;

	parity = 0;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			parity++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	if (!(parity % 2))
		return (num);
	return (-num);
}
