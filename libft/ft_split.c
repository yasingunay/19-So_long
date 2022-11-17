/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:33:54 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/17 16:39:50 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 1;
	n = 0;
	if (!(s[0]))
		return (0);
	if (s[0] != c)
		++n;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			++n;
		++i;
	}
	return (n);
}

static void	ft_free(char **spl, size_t i)
{
	while (i > 0)
	{
		free(spl[i]);
		--i;
	}
	free(spl[0]);
	free(spl);
}

static char	*ft_strndup(char const *str, size_t size)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_create_str(char **spl, char const *s, char c, int i)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s[start])
	{
		end = 0;
		while (s[start + end] && s[start + end] != c)
			++end;
		if (end > 0)
		{
			spl[i] = ft_strndup(s + start, end);
			if (!spl[i])
			{
				ft_free(spl, i);
				return (NULL);
			}
			++i;
			start = start + end;
		}
		if (s[start])
			++start;
	}
	spl[i] = NULL;
	return (spl);
}

char	**ft_split(char *s, char c)
{
	char	**spl;
	size_t	size;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	size = check_str(s, c);
	spl = (char **)malloc(sizeof(spl) * (size + 1));
	if (!spl)
		return (NULL);
	spl = ft_create_str(spl, s, c, i);
	if (s)
		free(s);
	return (spl);
}

// int main(void)
// {
// 	char	s[] = "yasin.gunay";
// 	char c = '.';
// 	char **ret;

// 	ret=ft_split(s,c);

// 	int j = 0;

// 	while (ret[j])
// 	{
// 		printf("str[%d] is %s\n'", j , ret[j]);
// 		j++;
// 	}
// 	printf("final amount of string is %d\n", j);
// 	free(ret);
// 	return (0);
// }
