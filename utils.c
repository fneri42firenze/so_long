/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:53:26 by fneri             #+#    #+#             */
/*   Updated: 2023/12/07 15:57:21 by fneri            ###   ########.fr       */
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

void	ft_error(char *errormessage, char **matr)
{
	if (matr)
		ft_free_matr(matr);
	ft_printf("\n============================"
		"\n%s\n============================\n\n", errormessage);
	exit(1);
}

int	ft_ber(char *map, char *ext)
{
	int	map_point;
	int	ext_point;

	map_point = ft_strlen(map);
	ext_point = ft_strlen(ext);
	if (map_point < ext_point)
		return (0);
	map += map_point - ext_point;
	while (*map)
	{
		if (*map != *ext)
			return (0);
		map++;
		ext++;
	}
	return (1);
}

int	ft_wrong_char(char c, char **map)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		ft_error("MAP CONTAINS WRONG CHARS", map);
	return (0);
}