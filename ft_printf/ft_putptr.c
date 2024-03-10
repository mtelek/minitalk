/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:23:12 by codespace         #+#    #+#             */
/*   Updated: 2023/11/17 13:11:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*create_string(unsigned long long value, int *strlen)
{
	int				i;
	unsigned long	temp;
	static char		str[21];

	i = 0;
	temp = value;
	if (temp == 0)
	{
		*strlen = 0;
		return (0);
	}
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	*strlen = i - 1;
	str[i--] = '\0';
	return (str);
}

int	ft_putptr(unsigned long value)
{
	char	*printout;
	int		i;

	printout = create_string(value, &i);
	if (!printout)
	{
		ft_putstr("(nil)");
		return (5);
	}
	while (i >= 0)
	{
		if ((value % 16) < 10)
			printout[i] = (value % 16) + 48;
		else
			printout[i] = (value % 16) + 87;
		value = value / 16;
		i--;
	}
	i = ft_strlen(printout);
	i += ft_putstr("0x");
	ft_putstr_fd(printout, 1);
	return (i);
}
