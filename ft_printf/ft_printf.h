/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:22:45 by codespace         #+#    #+#             */
/*   Updated: 2023/11/17 13:28:55 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *str, ...);
int			ft_printchar(char c);
int			ft_puthexlow(long n, int base);
int			ft_puthexupp(long n, int base);
int			ft_printint(int n);
int			ft_putstr(char *s);
int			ft_putuint(unsigned int c);
int			ft_putptr(unsigned long value);

#endif