/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:50:01 by codespace         #+#    #+#             */
/*   Updated: 2023/11/17 13:10:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		i;
	void	*str;

	str = (void *)ULONG_MAX;
	i = ft_printf("%p", str);
	ft_printf("|\n%d\n", i);
	i = 0;
	i = printf("%p", str);
	printf("|\n%d\n", i);
}

	//char    *str = NULL;
	// ft_result = ft_printf(NULL);
	// result = printf(NULL);
	// printf("ft_result: %d\n", ft_result);
	// printf("result: %d\n", result);