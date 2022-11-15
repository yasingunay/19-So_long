/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:24:28 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/18 16:13:29 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_print_hexa(unsigned int nb, const char format);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_nbr(int nbr);
int		ft_print_str(const char *s1);
int		ft_print_ptr(unsigned long nb);
int		ft_putchar(char c);
char	*ft_itoa(int n);

#endif
