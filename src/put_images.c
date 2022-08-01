#include "solong.h"

void	put_background(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	int	x;
	int	y;

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		mlx_put_image_to_window(solong->init, solong->win.window, imgs->content, x, y);
		objs = objs->next;
	}
}

void	put_walls(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	int	x;
	int	y;

	ft_find_element()

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		mlx_put_image_to_window(solong->init, solong->win.window, imgs->content, x, y);
		objs = objs->next;
	}
}