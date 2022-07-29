#include "solong.h"

void	init_display(t_mlx *solong, t_map *p_map)
{
	int	width;
	int	height;

	width = (p_map->width - 1) * 32;
	height = p_map->height * 32;
	solong -> init = mlx_init();
	solong -> win.width = width;
	solong -> win.height = height;
	solong -> win.window = mlx_new_window(solong -> init, \
		solong -> win.width, \
		solong -> win.height, \
		"So_Long");
	solong -> status = 1;
}

void	events_hook(t_mlx *solong)
{
	mlx_hook(solong -> win.window, 17, 1<<24, close_window, solong);
	mlx_key_hook(solong -> win.window, key_release, solong);
}

