/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:22:59 by codespace         #+#    #+#             */
/*   Updated: 2023/11/17 13:34:21 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_puthexlow(-n, base) + 1);
	}
	else if (n < base)
	{
		ft_printchar(symbols[n]);
		return (1);
	}
	else
	{
		count = ft_puthexlow(n / base, base);
		return (count + ft_puthexlow(n % base, base));
	}
}
