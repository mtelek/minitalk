/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:23:47 by codespace         #+#    #+#             */
/*   Updated: 2024/03/08 19:47:19 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include "ft_printf/ft_printf.h"

#define MULTIPLIER 2

int		ft_atoi(const char *str);
int		pid_checker(int argc, char **argv);
int		argc_checker(int argc, char **argv);
void	*ft_realloc(void *ptr, size_t size);
