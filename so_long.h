/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:12 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/23 15:27:19 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define PLAYER "graphic/oryx_16bit_scifi_creatures_1224.xpm"
# define WALL "graphic/oryx_16bit_scifi_world_35.xpm"
# define COLLEC "graphic/oryx_16bit_scifi_items_83.xpm"
# define EXIT "graphic/oryx_16bit_scifi_world_79.xpm"
# define EXIT_OPEN "graphic/oryx_16bit_scifi_world_78.xpm"
# define E_SPACE "graphic/oryx_16bit_scifi_world_832.xpm"
# define ENEMY "graphic/oryx_16bit_scifi_world_651.xpm"
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define ESC 53
# define QUIT 17

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	int			e;
	int			e_check;
	int			p;
	int			cb;
	int			cb_check;
	void		*mlx;
	void		*windows;
	char		**map;
	int			map_h;
	int			map_w;
	void		*wall;
	void		*player;
	void		*enemy;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	void		*collec;
	void		*e_space;
	void		*exit;
	void		*exit_open;
	int			count;
	int			end_x;
	int			end_y;
	t_vector	w_s;
	t_pos		*pos;

}t_game;

char	**ft_read_map(char *fmap);
void	ft_map_extension_control(char *map);
int		ft_map_weight(t_game *game);
int		ft_map_height(t_game *game);
int		ft_hook(int keycode, t_game *game);
int		ft_free_and_close(t_game *game);
void	ft_error(char *error);
void	ft_error_message(char *error);
void	ft_map_size_check(t_game *game);
void	ft_map_dup_check(t_game *game);
void	ft_convert_xpm_to_image(t_game *game, int x, int y);
void	ft_replace_map_with_image(t_game *game, char c, int x, int y);
void	ft_replace_map_with_image2(t_game *game, char c, int x, int y);
void	ft_init_window(t_game *game, int x, int y);
void	ft_render_map(t_game *game);
int		walk(int keycode, t_game *game);
void	move_p(t_game *game, int x, int y);
void	ft_put_score(t_game *game);
void	map_character_check(t_game *game);
void	wall_check(t_game *game);
void	ft_init_game(t_game *game);
void	map_dup_check(t_game *game);
int		ft_update(t_game *game);
void	ft_check_path(t_game *game);
char	**ft_dup_map(t_game *game);
void	ft_free_dup(char **dup);
void	ft_put_x(char **grid, int i, int j, t_game *game);

#endif
