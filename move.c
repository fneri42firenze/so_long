/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:47 by fneri             #+#    #+#             */
/*   Updated: 2023/12/12 14:06:52 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_window *data)
{
	data->stepx = 0;
	data->stepy = 0;
	if (keycode == 'w' || keycode == 65362)
		data->stepy = -1;
	else if (keycode == 'a' || keycode == 65361)
		data->stepx = -1;
	else if (keycode == 's' || keycode == 65364)
		data->stepy = 1;
	else if (keycode == 'd' || keycode == 65363)
		data->stepx = 1;
	else if (keycode == 65307)
		exit(0);
	move_authorize(data);
	return (0);
}

void	move_authorize(t_window *data)
{
	if (data->map[data->player_pos.y + data->stepy]
		[data->player_pos.x + data->stepx] != 'E')
	{
		if (data->map[data->player_pos.y + data->stepy]
			[data->player_pos.x + data->stepx] != '1')
		{
			if (data->map[data->player_pos.y + data->stepy]
				[data->player_pos.x + data->stepx] == 'C')
				data->collect += 1;
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			data->map[data->player_pos.y + data->stepy]
			[data->player_pos.x + data->stepx] = 'P';
			map_stamp(data);
		}
	}
	else if (data->collect == data->collectable
		&& data->map[data->player_pos.y + data->stepy]
		[data->player_pos.x + data->stepx] == 'E' )
		exit (0);
	ft_printf("%i\n", data->collect);
}
