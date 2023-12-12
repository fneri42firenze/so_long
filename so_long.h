/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:09:08 by fneri             #+#    #+#             */
/*   Updated: 2023/12/12 13:21:22 by fneri            ###   ########.fr       */
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
	int			player;
	int			door;
	int			size_x;
	int			size_y;
	int			stepx;
	int			stepy;
}				t_window;

t_img		img_convert(t_window *window);
t_vector	ft_find_player(char **map);
int			window_close(t_window *window);
int			key_press(int keycode, t_window *data);
int			ft_controlfile(int ac, char *file);
int			ft_ber(char *map, char *ext);
int			ft_wrong_char(char c, char **map);
int			ft_empty_lines(char *l);
int			ft_reachable(t_window *window);
char		**map_anal(char *mappa, t_window *window);
char		**ft_copy_matrix(char **window, int rows, int cols);
void		collectable_count(char **map, t_window *window);
void		draw_image(char stamp, t_window *window, t_vector coord);
void		ft_fill_top(t_window *data);
void		map_stamp(t_window *data);
void		ft_error(char *errormessage, char **matr);
void		ft_free_matr(char **matr);
void		ft_maprectangular(t_window *window);
void		ft_controlwall(t_window *window);
void		ft_errors_control(t_window *window);
void		ft_dfs(char **map, t_vector size, t_vector curr, t_window *wind);
void		ft_free_matrix(char **matr);
void		inizialize(t_window *window);
void		move_authorize(t_window *data);
#endif