/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:57:02 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 16:31:27 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/* NEED TO HANDLE ERROR -> PRINTF SHOULD RETURN -1 IF IT ENCOUNTERS AN ERROR */

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);
size_t	ft_putchar_pf(char c);
size_t	ft_putstr_pf(char *s);
size_t	ft_putnbr_pf(long long n, int not_unsigned);
size_t	ft_puthex(unsigned long n, int letter);
size_t	ft_pointer(void *ptr);

#endif