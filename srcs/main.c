/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/16 17:51:10 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"




void ft_init_game(t_game *game)
{
	int x;
	int y;
	x = 0;
	y = 0;
	
	
	game->count = 0;
	game->e = 0;
	game->cb = 0;
	game->p = 0;

	game->map_w=ft_map_weight(game);
    game->map_h=ft_map_height(game);
	map_character_check (game);
	ft_map_size_check(game);
	wall_check(game);
	ft_init_window(game,x,y);
	
}





int main(int ac, char **av)
{
    t_game game;
    if(ac != 2)
        ft_error("Invalid amount of arguments ");
	ft_map_extension_control(av[1]);
    
    game.map = ft_read_map(av[1]);

    ft_init_game(&game);
  
    mlx_hook(game.windows, 2, (1L << 0), walk, &game);
	mlx_hook(game.windows, 17, 0, ft_free_and_close, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



