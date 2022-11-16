/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:33:58 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/16 16:33:48 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_character_check (t_game *game)
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
			{
				game->cb +=1;
			}
				

			else if (game->map[i][j] == 'E')
			{
				game->e +=1;
			}
			
			else if (game->map[i][j] == 'P')
			{
				game->p +=1;
			}
			else if(game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != 'C' && game->map[i][j] != '1' && game->map[i][j] != '0')
				 ft_error("there are unauthorized character on the map");
			j++;
		}
		i++;
	}


	if(game->e != 1 || game->p != 1 || game->cb < 1 )   
    {
        ft_error_message("the map contains a duplicates characters or mandatory characters are missing. Game can not start");
        exit(1);
         
    }
	
}

     
       


 void ft_map_size_check (t_game *game)
{


        if(game->map_h == game->map_w)
        {
            ft_error_message("the map has to be rectangular ");
            exit(1);
        }


}



void ft_map_extension_control(char *map)
{
	int len;
	
	len = 0;
	len = ft_strlen(map);

	if(map[len-1] != 'r' || map[len-2] != 'e' ||  map[len-3] != 'b' || map[len-4] != '.')
		ft_error("the map file could not be found\n");
	
}



