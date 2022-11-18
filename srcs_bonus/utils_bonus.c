/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:49:57 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/18 17:38:38 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_free_and_close(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->mlx, game->collec);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->exit_open);
	mlx_destroy_image(game->mlx, game->e_space);
	mlx_destroy_image(game->mlx, game->player);
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	mlx_destroy_window(game->mlx, game->windows);
	write (1, "Thanks for playing !\n", 22);
	system("leaks so_long");
	exit(0);
	return (0);
}

void	ft_error(char *error)
{
	write (2, error, ft_strlen (error));
	exit(EXIT_FAILURE);
}

void	ft_error_message(char *error)
{
	write (2, error, ft_strlen (error));
}

void	ft_put_score(t_game *game)
{
	char	*score;

	score = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->windows, 10, 10, 0xFFFFFFFF, score);
	free(score);
}

int	ft_update(t_game *game)
{
	static int	frame;

	frame++;
	if (frame == 10)
	{
			game->p_y += 1;
	printf("1 %d\n",game->p_y);
	}
	else if (frame >= 20)
	{
		game->p_y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(game->mlx, game->windows, game->player, game->p_x, game->p_y);
	//printf("2 %d\n",game->p_y);
	return (0);
}
