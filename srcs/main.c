/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/09 17:30:17 by ygunay           ###   ########.fr       */
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
    game.map_size.map_w=map_weight(game);
    game.map_size.map_h=map_height(game);
    game.win_size.x=game.map_size.map_w * 200;
    game.win_size.y=game.map_size.map_h * 200;
    game.mlx = mlx_init();
    game.windows = mlx_new_window(game.mlx,game.win_size.x,game.win_size.y,"so_long");
    mlx_loop(game.mlx);

    return (0);
}



