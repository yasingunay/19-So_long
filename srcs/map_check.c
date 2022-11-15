/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:33:58 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 11:01:49 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int ft_map_dup_check (t_game *game)
// {
  
//         if(game->e != 1 || game->p != 1 || game->c < 1 )   
//         {
//             ft_error_message("the map contains a duplicates characters or mandatory characters are missing. Game can not start ");
//             return (0);
//         }
       
//         else
//             return (1);
       
// }

int ft_map_size_check (t_game *game)
{
  
       
        if(game->map_h == game->map_w)
        {
            ft_error_message("the map has to be rectangular ");
            return (0);
        }
        else
            return (1);
       
}



void ft_map_extension_control(char *map)
{
	int len;
	
	len = 0;
	len = ft_strlen(map);

	if(map[len-1] != 'r' || map[len-2] != 'e' ||  map[len-3] != 'b' || map[len-4] != '.')
		ft_error("the map file could not be found\n");
	
}



