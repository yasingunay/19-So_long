/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:56:25 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 19:06:27 by ygunay           ###   ########.fr       */
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
         
            if(c =='1')
                mlx_put_image_to_window(game->mlx,game->windows,game->wall,x ,y);

            else if(c =='P')
            {
                game->player->pos.x = x;
                game->player->pos.y = y;
                
                 mlx_put_image_to_window(game->mlx,game->windows,game->player,x ,y);
             
            }
            
            else if(c =='E')
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
                
            else
                ft_error("there are unauthorized character on the map");
            
            
         
    }


void	ft_put_score(t_game *game)
{
	char	*score;

	score = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->windows, 10, 10, 0xFFFFFFFF, score);
	free(score);
}




void ft_render_map (t_game *game)
{
    int i;
    int j;
    int x;
    int y;
   

    i = 0;
    j = 0;
    x = 0;
    y = 0;
  
    while (i < game->map_h)
        {
            j = 0;
            x = 0; 
            while(j < game->map_w)
            {
                ft_replace_map_with_image(game,game->map[i][j], x, y);
                ft_put_score(game);
                x = x + 24;
                
                j++;
            }       

            i++;    
            y = y + 24;    
        }

}


void ft_init_window(t_game *game, int x, int y)
{
    
    game->map_w=ft_map_weight(game);
    game->map_h=ft_map_height(game);
    game->win_size.x=game->map_w * 24;
    game->win_size.y=game->map_h * 24;

    game->mlx = mlx_init();
    game->windows = mlx_new_window(game->mlx,game->win_size.x,game->win_size.y,"so_long");

    ft_convert_xpm_to_image(game,x,y);
    ft_render_map(game);

}





