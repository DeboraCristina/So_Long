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
