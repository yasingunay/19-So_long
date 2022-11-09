/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:49:37 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/09 13:50:12 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> // open function
# include <stddef.h>
# include <unistd.h> //read, close function
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *buffer, char *buff);
//size_t	ft_strlen(char *s);
char	*ft_get_line(char *buffer);
char	*ft_next(char *buffer);

#endif
