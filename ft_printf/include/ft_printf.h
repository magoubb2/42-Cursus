/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:57:02 by marbaron          #+#    #+#             */
/*   Updated: 2024/03/28 14:55:34 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_strlen(char *str);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
int		ft_putnbr_pf(long long n, int not_unsigned);
int		ft_puthex(unsigned long n, int letter);
int		ft_pointer(void *ptr);

#endif