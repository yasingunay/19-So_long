/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/10 11:54:03 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int main(int ac, char **av)
{
    t_game game;
     
    if(ac != 2)
        ft_error("Invalid amount of arguments ");
	
	map_extension_control(av[1]);

    
    game.map = ft_get_map(av[1]);
    game.map_size.w=map_weight(game);
    game.map_size.h=map_height(game);
    game.win_size.x=game.map_size.w * 200;
    game.win_size.y=game.map_size.h * 200;
    game.mlx = mlx_init();
    game.windows = mlx_new_window(game.mlx,game.win_size.x,game.win_size.y,"so_long");
    mlx_key_hook(game.windows, hook, &game);
    mlx_hook(game.windows, QUIT, 0, free_and_close, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



