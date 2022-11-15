/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 18:58:18 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void cb_control (t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->cb +=1;
			j++;
		}
		i++;
	}

	
}




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
	cb_control(game);
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
  
    if(!ft_map_size_check(&game))
       ft_error("");
	   
    mlx_hook(game.windows, 2, (1L << 0), walk, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



