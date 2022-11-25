/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:49:57 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/25 11:46:55 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	exit(0);
	return (0);
}

void	ft_error(char *error)
{
	write (2, "Error\n", 6);
	write (2, error, ft_strlen (error));
	exit(EXIT_FAILURE);
}

void	ft_error_message(char *error)
{
	write (2, "Error\n", 6);
	write (2, error, ft_strlen (error));
}
