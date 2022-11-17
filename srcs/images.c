/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:13:22 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/17 19:32:08 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_convert_xpm_to_image(t_game *game, int x , int y)
{
    game->wall = mlx_xpm_file_to_image(game->mlx,WALL,&x,&y);
    game->collec= mlx_xpm_file_to_image(game->mlx,COLLEC,&x,&y);
    game->e_space = mlx_xpm_file_to_image(game->mlx,E_SPACE,&x,&y);
    game->exit= mlx_xpm_file_to_image(game->mlx,EXIT,&x,&y);
    game->exit_open= mlx_xpm_file_to_image(game->mlx,EXIT_OPEN,&x,&y);
    game->player = mlx_xpm_file_to_image(game->mlx,PLAYER,&x,&y);
}

void ft_replace_map_with_image(t_game *game,char c, int x, int y)
{

            if(c == 'P')
            {
               game->p_x = x;
               game->p_y = y;
                
                mlx_put_image_to_window(game->mlx,game->windows,game->player,x ,y);
             
            }
            
            
            else if(c =='1')
                mlx_put_image_to_window(game->mlx,game->windows,game->wall,x ,y);

           
            else if(c =='E' && game->cb > 0)
            {
                game->end_x = x;
                game->end_y = y;
                mlx_put_image_to_window(game->mlx,game->windows,game->exit,x ,y);
          
            }
             else if(c =='C')
             {
                mlx_put_image_to_window(game->mlx,game->windows,game->collec,x ,y);
           
             }  
            else if(c =='0')
                mlx_put_image_to_window(game->mlx,game->windows,game->e_space,x ,y);
            else if(game->cb == 0)
		        mlx_put_image_to_window(game->mlx,game->windows,game->exit_open,game->end_x ,game->end_y);
                 
    }
    