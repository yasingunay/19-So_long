/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:44:06 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 16:05:36 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_p(t_game *game, int x, int y)
{
	if(game->map[y / 24][x / 24] != 'E' && game->map[y / 24][x / 24] != '1')
	{
		game->count +=1;
		printf("number of movements-->%d\n",game->count);
	}
		
	if (game->map[y / 24][x / 24] != '1' && game->map[y / 24][x / 24] != 'E')
	{
		game->map[game->player->pos.y / 24][game->player->pos.x / 24] = '0';
		
		game->map[y / 24][x / 24] = 'P';
	}

}



int	walk(int keycode, t_game *game)
{
	
	mlx_clear_window(game->mlx, game->windows);
	if (keycode == RIGHT || keycode == D )
		move_p(game, game->player->pos.x + 24, game->player->pos.y );
	
	if (keycode == LEFT || keycode == A)
		move_p(game, game->player->pos.x  - 24, game->player->pos.y);
		
	if (keycode == UP || keycode == W)
		move_p(game,  game->player->pos.x , game->player->pos.y - 24);
		
	if (keycode == DOWN || keycode == S)
		move_p(game, game->player->pos.x , game->player->pos.y + 24);
	
	if (keycode == ESC)
		 ft_free_and_close(game);
		
	
	   
	
	ft_render_map(game);
	return (keycode);
}