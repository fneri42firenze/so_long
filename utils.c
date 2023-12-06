/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:53:26 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 16:54:00 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	window_close(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_window	window;

	window.collect = 0;
	if (argc != 2)
		return (1);
	window.map = map_anal(argv[1], &window);
	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x * 32,
			window.size_y * 32 + 30, "so_long");
	if (!window.win_ptr)
		return (free(window.mlx_ptr), 1);
	window.imgs = img_convert(&window);
	map_stamp(&window);
	mlx_hook(window.win_ptr, 2, KeyPressMask, &key_press, &window);
	mlx_hook(window.win_ptr, DestroyNotify, StructureNotifyMask,
		&window_close, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}