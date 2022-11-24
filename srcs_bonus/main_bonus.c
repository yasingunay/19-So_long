/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:20:50 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/24 14:46:19 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Invalid amount of arguments ");
	ft_map_extension_control(av[1]);
	game.map = ft_read_map(av[1]);
	ft_init_game(&game);
	mlx_hook(game.windows, 2, (1L << 0), walk, &game);
	mlx_hook(game.windows, 17, 0, ft_free_and_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
