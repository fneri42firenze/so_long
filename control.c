/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:32:50 by fneri             #+#    #+#             */
/*   Updated: 2023/12/15 15:04:02 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_controlfile(int argc, char *file)
{
	if (argc != 2)
	{
		ft_error("Use: ./so_long maps/file.ber", NULL);
		return (0);
	}
	else if (open(file, O_RDONLY) == -1)
	{
		ft_error("     MAP NOT FOUND", NULL);
		return (0);
	}
	else if (!ft_ber(file, ".ber"))
		ft_error("     MAP IS NOT A .ber", NULL);
	return (1);
}

void	ft_maprectangular(t_window *window)
{
	int	i;

	i = 0;
	while (window->map[i] && window->map[i + 1])
	{
		if (ft_strlen(window->map[i]) != ft_strlen(window->map[i + 1]))
			ft_error("MAP IS NOT RECTANGULAR", window->map);
		i++;
	}
}

void	ft_controlwall(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (i == 0 || j == 0 || i == window->size_y - 1
				|| j == window->size_x - 1)
			{
				if (window->map[i][j] != '1')
					ft_error("MAP IS NOT CLOSED", window->map);
			}
			ft_wrong_char(window->map[i][j], window->map);
			j++;
		}
		i++;
	}
}

int	ft_empty_lines(char *l)
{
	int	i;

	i = 0;
	while (l[i])
	{
		if (l[i] == '\n' && l[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_errors_control(t_window *window)
{
	if (window->collectable == 0)
		ft_error("Error\n        NO COLLECT", window->map);
	if (window->player != 1)
		ft_error("Error\nWRONG NUMBER OF PLAYERS, IT MUST BE ONE!",
			window->map);
	if (window->door != 1)
		ft_error("Error\nWRONG NUMBER OF EXITS, IT MUST BE ONE!", window->map);
	if (!ft_reachable(window))
		ft_error("Error\nDOOR IS NOT REACHABLE", window->map);
	ft_controlwall(window);
	ft_maprectangular(window);
}
