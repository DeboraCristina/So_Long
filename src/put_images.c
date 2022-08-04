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

int	render(t_mlx *solong)
{
	t_image	*img;
	int		x;
	int		y;
	void	*elem;

	if (!solong)
		return (1);
	while (solong->objs)
	{
		img = (t_image *) solong->objs->content;
		x = img->x;
		y = img->y;
		elem = ft_find_image(solong->xpm_images, img->name);
		mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
		solong->objs = solong->objs->next;
	}
	return (0);
}
