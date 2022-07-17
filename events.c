#include "solong.h"

int	close_window(t_mlx *solong)
{
	if (solong->win.window)
	{
		mlx_destroy_window(solong->instance, solong->win.window);
	}
	return (0);
}

int	key_release(int key, t_mlx *solong)
{
	if (key == K_ESCAPE)
		close_window(solong);
	return (0);
}

