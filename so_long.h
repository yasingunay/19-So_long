/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:12 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/10 10:26:22 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "libft/libft.h"



typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
    int h;
    int w;
}t_map;


typedef struct s_game
{
    void *mlx;
    void *windows;
    t_vector win_size;
    char **map;
    t_map map_size;
}t_game;





void ft_error(char *error);
char	**ft_get_map(char *fmap);
void map_extension_control(char *map);
int map_weight(t_game game);
int map_height(t_game game);




#endif
