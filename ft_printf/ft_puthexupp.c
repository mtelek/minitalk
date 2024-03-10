/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:04:54 by codespace         #+#    #+#             */
/*   Updated: 2023/11/17 13:34:19 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexupp(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_puthexupp(-n, base) + 1);
	}
	else if (n < base)
	{
		ft_printchar(symbols[n]);
		return (1);
	}
	else
	{
		count = ft_puthexupp(n / base, base);
		return (count + ft_puthexupp(n % base, base));
	}
}
