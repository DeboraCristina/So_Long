#include "solong.h"

int	close_window(t_mlx *solong)
{
	if (solong->win.window)
	{
		ft_lstclear(&solong->objs, free);
		ft_destroy_images(solong->init, solong->xpm_images);
		mlx_destroy_window(solong->init, solong->win.window);
	}
	return (0);
}

int	key_release(int key, t_mlx *solong)
{
	if (key == K_ESCAPE)
		close_window(solong);
	ft_printf("%d\n", key);
	if (ft_is_key_move(key))
		move_player(key, solong);
	return (0);
}

