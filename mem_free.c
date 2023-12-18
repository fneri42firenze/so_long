/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:11:46 by fneri             #+#    #+#             */
/*   Updated: 2023/12/18 18:27:58 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
