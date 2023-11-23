#include "libx/mlx.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_window
{
	void *mlx_ptr;
	void *win_ptr;
}        		t_window;

typedef struct s_img
{
	void *img_1;
	void *img_0;
	void *img_C;
	void *img_P;
	void *img_E;
	
}        		t_img;

typedef struct s_vector
{
	int x;
	int y;
}				t_vector;

int window_close(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(0);
	return (0);
}

int key_press(int keycode)
{
	ft_printf("Pressed Key: %d\n", keycode);
	return (0);
}

char **map_anal(char *mappa)
{
	char **map;
	char *buffer;
	int fd_open;

	buffer = malloc(sizeof(char) * 10000);
	fd_open = open(mappa, O_RDONLY);
	if(!fd_open)
		return(NULL);
	fd_open = read(fd_open, buffer, 10000);
	map = ft_split(buffer, '\n');
	free(buffer);
	return (map);
}

void draw_image(char stamp, t_window *window, t_img *image, t_vector coord)
{
    if(stamp == '1')
    	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_1, coord.x * 32, coord.y * 32);
	else if(stamp == '0')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_0, coord.x * 32, coord.y * 32);
	else if (stamp == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_C, coord.x * 32, coord.y * 32);
	else if(stamp == 'P')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_P, coord.x * 32, coord.y * 32);
	else if(stamp == 'E')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->img_E, coord.x * 32, coord.y * 32);
}

void map_stamp(char **stamp, t_window *window, t_img *image)
{
	t_vector coord;

	coord.y = 0;
	while(stamp[coord.y])
	{
		coord.x = 0;
		while(stamp[coord.y][coord.x])
		{
			draw_image(stamp[coord.y][coord.x], window, image, coord);
			coord.x++;
		}
		coord.y++;
	}
}

t_img img_convert(t_window *window)
{
	t_img image;
	int width = 32;
	int height = 32;
	image.img_1 = mlx_xpm_file_to_image(window->mlx_ptr, "textures/muro.xpm", &width, &height);
	image.img_0 = mlx_xpm_file_to_image(window->mlx_ptr, "textures/pavimento.xpm", &width, &height);
	image.img_C = mlx_xpm_file_to_image(window->mlx_ptr, "textures/caramelle.xpm", &width, &height);
	image.img_P = mlx_xpm_file_to_image(window->mlx_ptr, "textures/kitty.xpm", &width, &height);
	image.img_E = mlx_xpm_file_to_image(window->mlx_ptr, "textures/casa.xpm", &width, &height);

	return (image);
}

int main(int argc, char **argv) 
{
	char **map;
	t_window window;
	t_img	imgs;

	if(argc !=2)
		return(1);
	map = map_anal(argv[1]);
	window.mlx_ptr = mlx_init();
	if(!window.mlx_ptr)
		return (1);
	window.win_ptr = mlx_new_window(window.mlx_ptr, 600, 400, "so_long");
	if(!window.win_ptr)
		return (free(window.mlx_ptr), 1);
	imgs = img_convert(&window);
    window.win_ptr = mlx_new_window(window.mlx_ptr, 640, 640, "so_long"); // Creazione della finestra di 64x64 pixel	
	map_stamp(map, &window, &imgs);
	mlx_hook(window.win_ptr, 2, KeyPressMask, &key_press, NULL);
	mlx_hook(window.win_ptr, DestroyNotify, StructureNotifyMask, &window_close, &window);
	mlx_loop(window.mlx_ptr); // Loop principale (il programma rimarrà aperto finché la finestra non viene chiusa)
    return 0;
}
//mlx_hook(window.win_ptr, 2, KeyPressMask, &key_press, NULL);
//./a.out maps/map1.ber