/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 16:09:10 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void ft_start(t_game *game)
{
	int x;
	int y;
	x = 0;
	y = 0;
	
	game->count = 0;
	ft_init_window(game,x,y);
}


int main(int ac, char **av)
{
    t_game game;
    if(ac != 2)
        ft_error("Invalid amount of arguments ");
	ft_map_extension_control(av[1]);
    
    game.map = ft_read_map(av[1]);

    ft_start(&game);
  
    if(!ft_map_size_check(&game))
       ft_error("");
       
    mlx_hook(game.windows, 2, (1L << 0), walk, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



