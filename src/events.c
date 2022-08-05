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
	//ft_printf("%d\n", key);
	if (key == K_ESCAPE)
		close_window(solong);
	else if (key == K_W || key == K_S || key == K_A || key == K_D)
		move_player(key, solong);
	else if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
		move_player(key, solong);
	return (0);
}

void	move_player(int key, t_mlx *solong)
{
	if (!solong)
		return ;
	if (key == K_W || key == K_UP)
		move(solong->objs, 0, -SIZE);
	else if (key == K_S || key == K_DOWN)
		move(solong->objs, 0, SIZE);
	else if (key == K_A || key == K_LEFT)
		move(solong->objs, -SIZE, 0);
	else if (key == K_D || key == K_RIGHT)
		move(solong->objs, SIZE, 0);
}