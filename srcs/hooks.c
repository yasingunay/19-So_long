/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:47:41 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/11 10:13:05 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_and_close(t_game *game)
{
	
	mlx_destroy_window(game->mlx, game->windows);
	write (1, "Thanks for playing !\n", 22);

	exit (0);
}

int	hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_and_close(game);
	return (0);
}

