/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:59:32 by fneri             #+#    #+#             */
/*   Updated: 2023/12/07 17:43:37 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;

	ft_controlfile(argc, argv[1]);
	window.collect = 0;
	if (argc != 2)
		return (1);
	window.map = map_anal(argv[1], &window);
	ft_errors_control(&window);
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
