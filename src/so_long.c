#include "so_long.h"

int	ft_draw_background(t_data *mlx, int color)
{
	int	x;
	int	y;

	if (!mlx->win.win)
		return(1);
	y = 0;
	while (y < mlx->win.heigh)
	{
		x = 0;
		while (x < mlx->win.width)
		{
			x++;
			mlx_pixel_put(mlx->mlx, mlx->win.win, x, y, color);
		}
		y++;
	}
	return (0);
}
int	ft_draw_rect(t_data *mlx, t_rect rect)
{
	int	h;
	int	w;

	if (!mlx->win.win)
		return(1);
	h = rect.y;
	while (h < (rect.y + rect.heigh))
	{
		w = rect.x;
		while (w < (rect.x + rect.width))
		{
			mlx_pixel_put(mlx->mlx, mlx->win.win, w, h, rect.color);
			w ++;
		}
		h ++;
	}
	return (0);
}

int	update_window(t_data *mlx) //grafic or window???
{
	if (!mlx)
		return (1);
	ft_draw_background(mlx, WHITE);
	ft_draw_rect(mlx, (t_rect){0, 0, 50, 50, GREEN});
	return (0);
}

int	main(void)
{
	t_data	window;

	window.win.width = 320;
	window.win.heigh = 224;
	ft_printf("abre\n");
	window.mlx = mlx_init();
	window.win.win = mlx_new_window(window.mlx, window.win.width, window.win.heigh, "Hello, World!");
	mlx_loop_hook(window.mlx, update_window, &window);

	mlx_key_hook(window.win.win, ft_readInputKeys, &window);
	mlx_hook(window.win.win, 17, 1l<<24, ft_close_window, &window);

	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	ft_printf("fim\n");
}

