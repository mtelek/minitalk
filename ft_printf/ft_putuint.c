/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:23:25 by codespace         #+#    #+#             */
/*   Updated: 2023/10/07 23:01:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int c)
{
	char	buffer[11];
	int		length;
	int		i;

	length = 0;
	if (c == 0)
	{
		ft_printchar('0');
		return (1);
	}
	while (c > 0)
	{
		buffer[length++] = '0' + (c % 10);
		c /= 10;
	}
	i = length - 1;
	while (i >= 0)
	{
		ft_printchar(buffer[i]);
		i--;
	}
	return (length);
}
