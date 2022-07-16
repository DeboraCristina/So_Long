#include "so_long.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		index;

	index = (img->line_len * y) + ((img->bpp / 8) * x);
	pixel = img->addr + (index);

	*(int *)pixel = color;
}

void	ft_draw_background(t_data *mlx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->win.heigh)
	{
		x = 0;
		while (x < mlx->win.width)
		{
			x++;
			img_pixel_put(&mlx->img, x, y, color);
		}
		y++;
	}
}

void	ft_draw_rect(t_img *img, t_rect rect)
{
	int	h;
	int	w;

	h = rect.y;
	while (h < (rect.y + rect.heigh))
	{
		w = rect.x;
		while (w < (rect.x + rect.width))
		{
			img_pixel_put(img, w, h, rect.color);
			w ++;
		}
		h ++;
	}
}
