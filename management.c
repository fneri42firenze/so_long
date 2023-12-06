/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:08:47 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 15:57:34 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int window_close(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(0);
	return (0);
}

int key_press(int keycode, t_window *data)
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
	if(data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] != 'E')
	{
		if	(data->map[data->player_pos.y + data->stepy ][data->player_pos.x + data->stepx] != '1')
		{
			if(data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] == 'C')
				data->collect += 1;
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] = 'P';
			map_stamp(data);
		}
	}
	else if(data->collect == data->collectable && data->map[data->player_pos.y + data->stepy][data->player_pos.x + data->stepx] != 'E' )
			exit (0);
	ft_printf("%i\n", data->collect);
	return (0);
}

char **map_anal(char *mappa, t_window *window)
{
	char 	**map;
	char 	*buffer;
	char 	*line;
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

void collectable_count(char **map, t_window *window)
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
			j++;
		}
		i++;
	}
	window->size_x = j;
	window->size_y = i;
}

void draw_image(char stamp, t_window *window, t_vector coord)
{
    if (stamp == '1')
    	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->imgs.img_1, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == '0')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->imgs.img_0, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->imgs.img_C, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'P')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->imgs.img_P, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'E')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->imgs.img_E, coord.x * 32, coord.y * 32 + 30);
}
void ft_fill_top(t_window *data)
{
	int	i;
	int	j;
	
	i = 0;
	while(i < 30)
	{
		j = 0;
		while(j < data->size_x * 32)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, 0xFFC0CB);
			j++;
		}
		i++;
	}
}

void map_stamp(t_window *data)
{
	t_vector coord;

	coord.y = 0;
	ft_fill_top(data);
	while(data->map[coord.y])
	{
		coord.x = 0;
		while(data->map[coord.y][coord.x])
		{
			if(data->map[coord.y][coord.x] == 'P')
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

t_img img_convert(t_window *window)
{
	t_img image;

	int width = 32;
	int height = 32;
	image.img_1 = mlx_xpm_file_to_image(window->mlx_ptr, "textures/muro.xpm", &width, &height);
	image.img_0 = mlx_xpm_file_to_image(window->mlx_ptr, "textures/pavimento.xpm", &width, &height);
	image.img_C = mlx_xpm_file_to_image(window->mlx_ptr, "textures/caramelle.xpm", &width, &height);
	image.img_P = mlx_xpm_file_to_image(window->mlx_ptr, "textures/kitty.xpm", &width, &height);
	image.img_E = mlx_xpm_file_to_image(window->mlx_ptr, "textures/casa.xpm", &width, &height);

	return (image);
}

int main(int argc, char **argv) 
{
	//char 		**map;
	t_window 	window;

	window.collect = 0;
	if(argc != 2)
		return (1);
	window.map = map_anal(argv[1], &window);
	window.mlx_ptr = mlx_init();
	if(!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x * 32, window.size_y * 32 + 30, "so_long");
	if(!window.win_ptr)
		return (free(window.mlx_ptr), 1);
	window.imgs = img_convert(&window);
	map_stamp(&window);
	mlx_hook(window.win_ptr, 2, KeyPressMask, &key_press, &window);
	mlx_hook(window.win_ptr, DestroyNotify, StructureNotifyMask, &window_close, &window);
	mlx_loop(window.mlx_ptr); // Loop principale (il programma rimarrà aperto finché la finestra non viene chiusa)
    return 0;
}