/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:25 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/23 15:28:18 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (game->map[i][j])
		{
			ft_replace_map_with_image(game, game->map[i][j], x, y);
			x = x + 24;
			j++;
		}
		i++;
		y = y + 24;
	}
}

void	ft_init_window(t_game *game, int x, int y)
{
	game->w_s.x = game->map_w * 24 ;
	game->w_s.y = game->map_h * 24;
	game->mlx = mlx_init();
	game->windows = mlx_new_window(game->mlx, game->w_s.x, game->w_s.y, "s");
	ft_convert_xpm_to_image(game, x, y);
	ft_render_map(game);
}

void	ft_init_game(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->count = 0;
	game->e = 0;
	game->cb = 0;
	game->p = 0;
	game->map_w = ft_map_weight(game);
	game->map_h = ft_map_height(game);
	map_character_check (game);
	map_dup_check(game);
	ft_map_size_check(game);
	wall_check(game);
	ft_check_path(game);
	ft_init_window(game, x, y);
}
