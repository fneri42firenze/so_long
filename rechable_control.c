/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rechable_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:45:41 by fneri             #+#    #+#             */
/*   Updated: 2023/12/07 17:25:33 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_reachable(t_window *window)
{
	t_vector	curr;
	t_vector	size;
	t_window	wind;
	char		**window_copy;

	curr = ft_find_player(window->map);

	size.x = window->size_x;
	size.y = window->size_y;

	wind.collectable = 0;
	wind.door = 0;

	window_copy = ft_copy_matrix(window->map, size.y, size.x);
	ft_dfs(window_copy, size, curr, &wind);
	ft_free_matrix(window_copy);

	if (wind.door != 1 || wind.collectable != window->collect)
		return (0);
	return (1);
}

t_vector	ft_find_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return ((t_vector){j, i});
			j++;
		}
		i++;
	}
	return ((t_vector){-1, -1});
}

void	ft_dfs(char **map, t_vector size, t_vector curr, t_window *wind)
{
	if (curr.x < 0 || curr.x + 1 >= size.x || curr.y < 0
		|| curr.y + 1 >= size.y || map[curr.y][curr.x] == '1')
		return ;
	if (map[curr.y][curr.x] == 'E')
		wind->door++;
	else if (map[curr.y][curr.x] == 'C')
		wind->collect++;
	map[curr.y][curr.x] = '1';
	ft_dfs(map, size, (t_vector){curr.x - 1, curr.y}, wind);
	ft_dfs(map, size, (t_vector){curr.x, curr.y - 1}, wind);
	ft_dfs(map, size, (t_vector){curr.x + 1, curr.y}, wind);
	ft_dfs(map, size, (t_vector){curr.x, curr.y + 1}, wind);
}

char	**ft_copy_matrix(char **window, int rows, int cols)
{
	char	**duplicate;
	int		i;

	duplicate = malloc(sizeof(char *) * (rows + 1));
	i = 0;
	while (window[i])
	{
		duplicate[i] = malloc(sizeof(char) * cols);
		ft_memcpy(duplicate[i], window[i], sizeof(char) * cols);
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}
