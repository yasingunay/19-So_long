/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:12 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/10 11:53:23 by ygunay           ###   ########.fr       */
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

// # define PLAYER "graphic/oryx_16bit_scifi_creatures_1224.xpm"
// # define WALL "graphic/oryx_16bit_scifi_world_35.xpm"
// # define COLLECTIBLE "graphic/oryx_16bit_scifi_items_83.xpm"
// # define E_CLOSE "graphic/oryx_16bit_scifi_world_79.xpm"
// # define E_OPEN "graphic/oryx_16bit_scifi_world_78.xpm"
// # define SPACE "graphic/oryx_16bit_scifi_world_832.xpm"
// # define W 13
// # define A 0
// # define S 1
// # define D 2
// # define UP 126
// # define LEFT 123
// # define DOWN 125
// # define RIGHT 124
# define ESC 53
# define QUIT 17


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





char	**ft_get_map(char *fmap);
void map_extension_control(char *map);
int map_weight(t_game game);
int map_height(t_game game);
int	hook(int keycode, t_game *game);
int	free_and_close(t_game *game);
void ft_error(char *error);




#endif
