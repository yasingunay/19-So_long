/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:25 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/11 16:12:15 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_convert_xpm_to_image(t_game *game)
{

    int measure;

    measure = 24;
    game->wall = mlx_xpm_file_to_image(game->mlx,WALL,&measure,&measure);
    game->collec= mlx_xpm_file_to_image(game->mlx,COLLEC,&measure,&measure);
    game->e_space = mlx_xpm_file_to_image(game->mlx,E_SPACE,&measure,&measure);
    game->exit= mlx_xpm_file_to_image(game->mlx,EXIT,&measure,&measure);
    game->player = mlx_xpm_file_to_image(game->mlx,PLAYER,&measure,&measure);
      
}

void ft_replace_map_with_image(t_game *game, int m)
{
    int i= 0;
    game->e = 0;
    game->p = 0;
    game->c = 0;

    while (i < game->map_h)
    {
        int j=0;
        while(j < game->map_w)
        {
            if(game->map[i][j]=='1')
                mlx_put_image_to_window(game->mlx,game->windows,game->wall,j * m ,i * m);

            else if(game->map[i][j]=='P')
            {
                 mlx_put_image_to_window(game->mlx,game->windows,game->player,j * m ,i * m);
                 game->p++;
            }
            
            else if(game->map[i][j]=='E')
            {
                mlx_put_image_to_window(game->mlx,game->windows,game->exit,j * m ,i * m);
                game->e++;
            }
             else if(game->map[i][j]=='C')
             {
                mlx_put_image_to_window(game->mlx,game->windows,game->collec,j * m ,i * m);
                game->c++;
             }
                
            
            else if(game->map[i][j]=='0')
                mlx_put_image_to_window(game->mlx,game->windows,game->e_space,j * m ,i * m);
            
            else
                ft_error("there are unauthorized character on the map");
            
            j++;
        }       

        i++;        
    }

}

void ft_init_window(t_game *game)
{
    
    game->map_w=ft_map_weight(game);
    game->map_h=ft_map_height(game);
    game->win_size.x=game->map_w * 24;
    game->win_size.y=game->map_h * 24;

    game->mlx = mlx_init();
    game->windows = mlx_new_window(game->mlx,game->win_size.x,game->win_size.y,"so_long");

    ft_convert_xpm_to_image(game);
    ft_replace_map_with_image(game, 24);

}