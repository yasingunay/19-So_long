/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:08:04 by ygunay            #+#    #+#             */
/*   Updated: 2022/11/09 17:27:27 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_get_map(char *fmap)
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
	if (all_lines[0] == '\0')
		ft_error("all_lines ");
	return (ft_split(all_lines, '\n'));
}


void map_extension_control(char *map)
{
	int len;
	
	len = 0;
	len = ft_strlen(map);

	if(map[len-1] != 'r' || map[len-2] != 'e' ||  map[len-3] != 'b' || map[len-4] != '.')
		ft_error("the map file could not be found\n");
	
}

int map_height(t_game game)
{

	int i;

	i = 0;
	while(game.map[i])
		i++;
	
	return (i);
}

int map_weight(t_game game)
{

	int i;

	i = 0;
	while(game.map[1][i])
		i++;
	
	return (i);
}

