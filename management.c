/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:47 by fneri             #+#    #+#             */
/*   Updated: 2023/12/07 17:48:13 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_window *data)
{
	data->stepx = 0;
	data->stepy = 0;
	if (keycode == 'w')
		data->stepy = -1;
	else if (keycode == 'a')
		data->stepx = -1;
	else if (keycode == 's')
		data->stepy = 1;
	else if (keycode == 'd')
		data->stepx = 1;
	if (data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] != 'E')
	{
		if (data->map[data->player_pos.y + data->stepy ][data->player_pos.x + data->stepx] != '1')
		{
			if (data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] == 'C')
				data->collect += 1;
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] = 'P';
			map_stamp(data);
		}
	}
	else if (data->collect == data->collectable && data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] != 'E' )
			exit (0);
	ft_printf("%i\n", data->collect);
	return (0);
}

void	collectable_count(char **map, t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				window->collectable++;
			else if (map[i][j] == 'P')
				window->player++;
			else if (map[i][j] == 'E')
				window->door++;
			j++;
		}
		i++;
	}
	window->size_x = j;
	window->size_y = i;
}

void	ft_fill_top(t_window *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < data->size_x * 32)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, 0xFFC0CB);
			j++;
		}
		i++;
	}
}