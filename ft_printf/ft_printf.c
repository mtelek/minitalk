/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:24:43 by mtelek            #+#    #+#             */
/*   Updated: 2023/11/17 13:35:02 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list va, char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (str[i] == 'c')
		count += ft_printchar(va_arg(va, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(va, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_printint(va_arg(va, int));
	else if (str[i] == 'p')
		count += ft_putptr(va_arg(va, unsigned long));
	else if (str[i] == 'u')
		count += ft_putuint(va_arg(va, unsigned int));
	else if (str[i] == '%')
		count += ft_printchar(*str);
	else if (str[i] == 'x' || str[i] == 'X')
	{
		if (str[i] == 'x')
			count += ft_puthexlow(va_arg(va, unsigned int), 16);
		else
			count += ft_puthexupp(va_arg(va, unsigned int), 16);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(va, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += format(va, (char *)(++str));
		else
			count += write(1, str, 1);
		++str;
	}
	va_end(va);
	return (count);
}
