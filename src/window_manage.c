#include "solong.h"

void	init_display(t_mlx *solong)
{
	solong -> instance = mlx_init();
	solong -> win.width = 320;
	solong -> win.height = 224;
	solong -> win.window = mlx_new_window(solong -> instance, solong -> win.width, solong -> win.height, "So_Long");
	solong -> status = 1;
}

void	events_hook(t_mlx *solong)
{
	mlx_hook(solong -> win.window, 17, 1<<24, close_window, solong);
	mlx_key_hook(solong -> win.window, key_release, solong);
}

