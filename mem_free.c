/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:11:46 by fneri             #+#    #+#             */
/*   Updated: 2023/12/12 12:53:25 by fneri            ###   ########.fr       */
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

void	ft_free_matrix(char **matr)
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
