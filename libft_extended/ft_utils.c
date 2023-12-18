/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:39:28 by fneri             #+#    #+#             */
/*   Updated: 2023/12/18 19:58:45 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matr(char **matr)
{
	int	i;

	i = 0;
	while (matr[i])
	{
		free(matr[i]);
		i++;
	}
	free(matr);
}

char	*ft_freejoin(char *buffer, char *line)
{
	char	*temp;

	temp = ft_strjoin(buffer, line);
	free(buffer);
	free(line);
	return (temp);
}

char	*ft_partial_freejoin(char *buffer, char *line, int op)
{
	char	*temp;

	temp = ft_strjoin(buffer, line);
	if (op == 1)
		free(buffer);
	else if (op == 2)
		free(line);
	return (temp);
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
	duplicate[i] = 0;
	return (duplicate);
}
