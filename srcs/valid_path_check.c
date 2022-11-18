/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:45:57 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/18 16:02:47 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_path(t_game *game)
{
	char	**temp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->cb_check = 0;
	game->e_check = 0;
	temp = ft_dup_map(game);
	while (temp[y] && temp[y][x] != 'P')
	{
		x = 0;
		y++;
		while (temp[y][x] && temp[y][x] != 'P')
			x++;
	}
	ft_put_x(temp, x, y, game);
	if (game->cb_check != game->cb || game->e_check != game->e)
		ft_error("No Valid Path!\n");
	ft_free_dup(temp);
	return ;
}

char	**ft_dup_map(t_game *game)
{
	char	**res;
	char	*temp;
	int		y;

	y = 0;
	while (game->map[y])
	{
		y++;
	}
	res = ft_calloc(y + 1, sizeof(char *));
	y = 0;
	while (game->map[y])
	{
		temp = ft_strdup(game->map[y]);
		res[y] = temp;
		y++;
	}
	return (res);
}

void	ft_free_dup(char **dup)
{
	int	x;

	x = 0;
	while (dup[x])
	{
		free(dup[x]);
		x++;
	}
	free(dup);
	return ;
}

void	ft_put_x(char **grid, int i, int j, t_game *game)
{
	int	x;
	int	y;

	if (grid[j][i] == 'C')
		game->cb_check ++;
	if (grid[j][i] == 'E')
		game->e_check = 1;
	x = game->map_w;
	y = game->map_h;
	if (i < 0 || i >= x || j < 0 || j >= y || grid[j][i] == '1'
	|| grid[j][i] == 'X' || grid[j][i] == 'E')
		return ;
	grid[j][i] = 'X';
	ft_put_x(grid, i, j + 1, game);
	ft_put_x(grid, i, j - 1, game);
	ft_put_x(grid, i + 1, j, game);
	ft_put_x(grid, i - 1, j, game);
	return ;
}
