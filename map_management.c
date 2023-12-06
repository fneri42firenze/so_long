/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gesture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:52:31 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 16:52:32 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_stamp(t_window *data)
{
	t_vector	coord;

	coord.y = 0;
	ft_fill_top(data);
	while (data->map[coord.y])
	{
		coord.x = 0;
		while (data->map[coord.y][coord.x])
		{
			if (data->map[coord.y][coord.x] == 'P')
			{
				data->player_pos.x = coord.x;
				data->player_pos.y = coord.y;
			}
			draw_image(data->map[coord.y][coord.x], data, coord);
			coord.x++;
		}
		coord.y++;
	}
}

char	**map_anal(char *mappa, t_window *window)
{
	char	**map;
	char	*buffer;
	char	*line;
	int		fd_open;

	map = NULL;
	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	fd_open = open(mappa, O_RDONLY);
	if (fd_open)
	{
		while (1)
		{
			line = get_next_line(fd_open);
			if (!line)
				break ; 
			buffer = ft_strjoin(buffer, line);
			free(line);
		}
		map = ft_split(buffer, '\n');
	}
	collectable_count(map, window);
	free(buffer);
	return (map);
}