/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:47 by fneri             #+#    #+#             */
/*   Updated: 2023/12/18 19:30:31 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int keycode, t_window *data)
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
		ft_window_close(data);
	ft_move_authorize(data);
	ft_display(data);
	return (0);
}

void	ft_display(t_window *data)
{
	char	*move_str;
	char	*collect_str;

	move_str = ft_partial_freejoin("MOVE NUMBER: ", ft_itoa(data->move_count), 2);
	collect_str = ft_partial_freejoin("COLLECTED: ", ft_itoa(data->collect), 2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 15, 0xffffff, collect_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 25, 0xffffff, move_str);
	free(move_str);
	free(collect_str);
}

void	ft_move_authorize(t_window *data)
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
			ft_map_stamp(data);
			data->move_count++;
		}
	}
	else if (data->collect == data->collectable
		&& data->map[data->player_pos.y + data->stepy]
		[data->player_pos.x + data->stepx] == 'E' )
	{
		ft_window_close(data);
		data->move_count++;
	}
}
