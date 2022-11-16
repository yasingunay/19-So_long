/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:38:32 by ygunay            #+#    #+#             */
/*   Updated: 2022/07/26 10:06:25 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <stdlib.h>
*	DESCRIPTION
*	The calloc() function contiguously allocates enough space for count objects 
*	that are size bytes of memory each and returns a pointer to the allocated 
*	memory.  The allocated memory is filled with bytes of value zero.
*	PARAMETERS
*	#1. The count of objects to allocate.
*	#2. The size of bytes in each object.
*	RETURN VALUES
*	If successful, calloc() function returns a pointer to allocated memory. 
*	If there is an error, they return a NULL pointer.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//   int *ip, id;

//   ip = (int *) ft_calloc(5, sizeof(int));

//   for (id=0; id<5; id++) {
//        *(ip+id) = (id+1) * 10;
//        printf("%p adresindeki değer: %d\n", (ip+id), *(ip+id));
//   }

//   free(ip);

//   return 0;
// }
