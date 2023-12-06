/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:52:22 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 17:37:43 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_convert(t_window *window)
{
	t_img	image;
	int		width;
	int		height;

	height = 32;
	width = 32;
	image.img_1 = mlx_xpm_file_to_image(window->mlx_ptr,
			"textures/muro.xpm", &width, &height);
	image.img_0 = mlx_xpm_file_to_image(window->mlx_ptr,
			"textures/pavimento.xpm", &width, &height);
	image.img_c = mlx_xpm_file_to_image(window->mlx_ptr,
			"textures/caramelle.xpm", &width, &height);
	image.img_p = mlx_xpm_file_to_image(window->mlx_ptr,
			"textures/kitty.xpm", &width, &height);
	image.img_e = mlx_xpm_file_to_image(window->mlx_ptr,
			"textures/casa.xpm", &width, &height);
	return (image);
}

void	draw_image(char stamp, t_window *window, t_vector coord)
{
	if (stamp == '1')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->imgs.img_1, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == '0')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->imgs.img_0, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->imgs.img_c, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'P')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->imgs.img_p, coord.x * 32, coord.y * 32 + 30);
	else if (stamp == 'E')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->imgs.img_e, coord.x * 32, coord.y * 32 + 30);
}