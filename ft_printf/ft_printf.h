/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:57:02 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/12 11:33:54 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar_fd_pf(char c);
size_t	ft_putstr_fd_pf(char *s);
// size_t	ft_putnbr_fd_pf(int n);
size_t	ft_putnbr_fd_pf(long long n, int not_unsigned);
// size_t	ft_unsigned_fd_pf(unsigned int n);
int		ft_strlen(char *str);
size_t	ft_puthex(unsigned int n, int letter);

#endif