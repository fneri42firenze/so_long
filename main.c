/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:59:32 by fneri             #+#    #+#             */
/*   Updated: 2023/12/12 16:48:13 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;

	ft_inizialize(&window);
	ft_controlfile(argc, argv[1]);
	if (argc != 2)
		return (1);
	window.map = ft_map_anal(argv[1], &window);
	ft_errors_control(&window);
	window.mlx_ptr = mlx_init();
	if (!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.size_x * 32,
			window.size_y * 32 + 30, "so_long");
	if (!window.win_ptr)
		return (free(window.mlx_ptr), 1);
	window.imgs = ft_img_convert(&window);
	ft_map_stamp(&window);
	mlx_hook(window.win_ptr, 2, KeyPressMask, &ft_key_press, &window);
	mlx_hook(window.win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_window_close, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
