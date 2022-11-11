/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:12 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/11 16:56:17 by ygunay           ###   ########.fr       */
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

# define PLAYER "graphic/oryx_16bit_scifi_creatures_1224.xpm"
# define WALL "graphic/oryx_16bit_scifi_world_35.xpm"
# define COLLEC "graphic/oryx_16bit_scifi_items_83.xpm"
# define EXIT "graphic/oryx_16bit_scifi_world_79.xpm"
# define E_SPACE "graphic/oryx_16bit_scifi_world_832.xpm"
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



typedef struct s_game
{
    int e;
    int p;
    int c;
    void *mlx;
    void *windows;
    t_vector win_size;
    char **map;
    int map_h;
    int map_w;
    void *wall;
    void *player;
    void *collec;
    void *e_space;
    void *exit;
   
    
    
}t_game;





char	**ft_read_map(char *fmap);
void ft_map_extension_control(char *map);
int ft_map_weight(t_game *game);
int ft_map_height(t_game *game);
int	ft_hook(int keycode, t_game *game);
int	ft_free_and_close(t_game *game);
void ft_error(char *error);
void ft_error_message(char *error);
int ft_map_size_check (t_game *game);
int ft_map_dup_check (t_game *game);
void ft_convert_xpm_to_image(t_game *game);
void ft_replace_map_with_image(t_game *game, int m);
void ft_init_window(t_game *game);




#endif
