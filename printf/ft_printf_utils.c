/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:05:28 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/18 15:34:27 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(const char *s1)
{
	int	i;

	i = 0;
	if (s1 == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s1[i])
	{
		write (1, &s1[i], 1);
		i++;
	}
	return (i);
}

static size_t	ft_get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long int	nb;
	char		*result;

	len = ft_get_len(n);
	nb = n;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	if (n == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (nb)
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (result);
}

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*nb;

	nb = ft_itoa(nbr);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}
