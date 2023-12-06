/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:32:50 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 20:10:11 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_checkfile(int argc, char *file)
{
	if (argc != 2)
	{
		ft_error("Use: ./so_long maps/file.ber", NULL);
		return (0);
	}
	else if (!ft_ber(file, ".ber"))
		ft_error("     MAP IS NOT A .ber", NULL);
	return (1);
}
