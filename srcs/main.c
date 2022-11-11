/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/11 16:56:09 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int ac, char **av)
{
    t_game game;
    if(ac != 2)
        ft_error("Invalid amount of arguments ");
	ft_map_extension_control(av[1]);
    
    game.map = ft_read_map(av[1]);

    ft_init_window(&game);
  
    if(!ft_map_dup_check (&game) || !ft_map_size_check(&game))
       ft_error("");
       
    mlx_key_hook(game.windows, ft_hook, &game);
    mlx_hook(game.windows, QUIT, 0, ft_free_and_close, &game);
    mlx_loop(game.mlx);
    

    return (0);
}



