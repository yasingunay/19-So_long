/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:44:06 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/16 15:19:41 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_p(t_game *game, int x, int y)
{

	
		
	
		
	if(game->cb == 0 && game->map[y / 24][x / 24] == 'E')
	{
		game->count +=1;
		ft_printf("number of movements-->%d\n",game->count);
		ft_printf("win!\n");
		ft_free_and_close(game);
		
	}

	if(game->map[y / 24][x / 24] != '1' && game->map[y / 24][x / 24] != 'E')
	{
		game->count +=1;
		
		if(game->map[y / 24][x / 24] == 'C')
			game->cb -=1;
			

		game->map[game->p_y/ 24][game->p_x / 24] = '0';

		game->map[game->end_y / 24][game->end_x / 24] = 'E';
		
		game->map[y / 24][x / 24] = 'P';
		ft_printf("number of movements-->%d\n",game->count);
		

	}
	
	
	
	
	

	
}


int	walk(int keycode, t_game *game)
{
	
	mlx_clear_window(game->mlx, game->windows);
	
	if (keycode == RIGHT || keycode == D )
		move_p(game, game->p_x + 24, game->p_y );
	
	if (keycode == LEFT || keycode == A)
		move_p(game, game->p_x  - 24, game->p_y);
		
	if (keycode == UP || keycode == W)
		move_p(game,  game->p_x , game->p_y - 24);
		
	if (keycode == DOWN || keycode == S)
		move_p(game, game->p_x , game->p_y + 24);
	
	if (keycode == ESC)
		 ft_free_and_close(game);
		
	
	   
	
	ft_render_map(game);
	return (keycode);
}