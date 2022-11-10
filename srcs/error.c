/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:49:57 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/10 16:21:54 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error(char *error)
{
    write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void ft_error_message(char *error)
{
    write(2, error, ft_strlen(error));
}