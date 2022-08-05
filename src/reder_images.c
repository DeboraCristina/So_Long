#include "solong.h"

static void	*ft_find_image(t_list *imgs, char *index)
{
	int	i;

	i = 0;
	while (i < ft_atoi(index))
	{
		imgs = imgs->next;
		i ++;
	}
	return (imgs->content);
}

static void	put_images(t_list *objs, t_mlx *solong)
{
	t_image	*img;
	int		x;
	int		y;
	void	*elem;

	if (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		elem = ft_find_image(solong->xpm_images, img->name);
		put_images(objs->next, solong);
		mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
	}
}

int	render(t_mlx *solong)
{

	if (!solong)
		return (1);
	put_images(solong->objs, solong);
	return (0);
}
