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

void abc(t_data *mlx)
{
	int	i = 0;

	while (i < 32)
		ft_draw_rect(&mlx->img, (t_rect){i + 32, 0, 32, 32, GREEN});
	//ft_draw_rect(&mlx->img, (t_rect){32, 0, 32, 32, GREEN});
}

int	update_window(t_data *mlx)
{
	void	*img;

	if (!mlx)
		return (1);
	int	x=32;
	img = mlx_xpm_file_to_image(mlx->mlx, "./coletable01_32.xpm", &x, &x);
	if (!img)
		return (1);
	ft_draw_background(mlx, WHITE);
	abc(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win.win, mlx->img.mlx_img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win.win, img, 0, 0);
	return (0);
}
