/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:15:51 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/05 12:01:32 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	   The strdup() function returns a pointer to a new string which is
       a duplicate of the string s.  Memory for the new string is
       obtained with malloc(3), and can be freed with free(3).

RETURN VALUE         
       On success, the strdup() function returns a pointer to the
       duplicated string.  It returns NULL if insufficient memory was
       available, with errno set to indicate the error.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;
	size_t	size;

	size = ft_strlen(s) + 1;
	dst = (char *) malloc (size * sizeof (char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// int main(void)
// {
// char *p1= "yasin";
// char *p2;
// p2=ft_strdup(p1);
// printf("duplicated string is : %s\n", p2);
// return (0);
// }

// int main(void)
// {
// char str[]="yasin";
// printf("or %s\n",strdup(str));

// char str2[]="yasin";
// printf("ft %s\n",ft_strdup(str2));

//  return 0;
// }
