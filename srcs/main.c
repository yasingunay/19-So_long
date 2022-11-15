/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 15:34:21 by yasingunay       ###   ########.fr       */
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
		//game->map[pnc->map->gate_y / 64][pnc->map->gate_x / 64] = 'E';
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

void ft_start(t_game *game)
{
	game->count = 0;
}





int main(int ac, char **av)
{
    t_game game;
	ft_start(&game);
    if(ac != 2)
        ft_error("Invalid amount of arguments ");
	ft_map_extension_control(av[1]);
    
    game.map = ft_read_map(av[1]);

    ft_init_window(&game);
  
    if(!ft_map_size_check(&game))
       ft_error("");
       
    mlx_hook(game.windows, 2, (1L << 0), walk, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



