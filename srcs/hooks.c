/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:47:41 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/15 19:05:30 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_free_and_close(t_game *game)
{
	
	mlx_destroy_window(game->mlx, game->windows);
	write (1, "Thanks for playing !\n", 22);

	exit (0);

}



