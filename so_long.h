/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:09:08 by fneri             #+#    #+#             */
/*   Updated: 2023/12/06 20:31:19 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "libft_extended/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_img
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_p;
	void	*img_e;

}				t_img;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	player_pos;
	t_img		imgs;
	char		**map;
	int			collect;
	int			collectable;
	int			size_x;
	int			size_y;
	int			stepx;
	int			stepy;
}				t_window;

int		window_close(t_window *window);
int		key_press(int keycode, t_window *data);
int		ft_checkfile(int ac, char *file);
char	**map_anal(char *mappa, t_window *window);
void	collectable_count(char **map, t_window *window);
void	draw_image(char stamp, t_window *window, t_vector coord);
void	ft_fill_top(t_window *data);
void	map_stamp(t_window *data);
t_img	img_convert(t_window *window);
void	ft_error(char *errormessage, char **matr);
void	ft_free_matr(char **matr);
int 	ft_ber(char *map, char *ext);

#endif