/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:08:04 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/17 19:41:44 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_read_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = NULL;
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		ft_error("the map file open error");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (!all_lines)
	{
		write(1, "Empty map !\n", 13);
		exit(1);
	}
	if (all_lines[0] == '\0')
		ft_error("all_lines ");
	return (ft_split(all_lines, '\n'));
}

int	ft_map_height(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

int	ft_map_weight(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[1][i])
		i++;
	return (i);
}
