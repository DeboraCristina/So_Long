#include "so_long.h"

int	ft_close_window(t_data *window)
{
	if (window)
	{
		ft_printf("fecha\n");
		mlx_clear_window(window->mlx, window->win.win);
 		mlx_destroy_window(window->mlx, window->win.win);
		window->win.win = NULL;
	}
	return (0);
}

int	update_window(t_data *mlx)
{
	if (!mlx)
		return (1);
	ft_draw_background(mlx, WHITE);
	ft_draw_rect(&mlx->img, (t_rect){0, 0, 50, 50, GREEN});
	mlx_put_image_to_window(mlx->mlx, mlx->win.win, mlx->img.mlx_img, 0, 0);
	return (0);
}
