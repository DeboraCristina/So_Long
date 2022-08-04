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

void	put_background(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = solong.xpm_images->content;
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
		solong.objs = solong.objs->next;
	}
}

void	put_walls(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = ft_find_image(solong.xpm_images, "1");
	elem = solong.xpm_images->next->content;
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "1"))
			mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
		solong.objs = solong.objs->next;
	}
}

void	put_player(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = ft_find_image(solong.xpm_images, "2");
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "2"))
		{
			mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
			break ;
		}
		solong.objs = solong.objs->next;
	}
}

void	put_exit(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = ft_find_image(solong.xpm_images, "3");
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "3"))
			mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
		solong.objs = solong.objs->next;
	}
}

void	put_collectable(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = ft_find_image(solong.xpm_images, "4");
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "4"))
			mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
		solong.objs = solong.objs->next;
	}
}

void	put_enemy(t_mlx solong)
{
	t_image	*img;
	void	*elem;
	int		x;
	int		y;

	elem = ft_find_image(solong.xpm_images, "5");
	while (solong.objs)
	{
		img = (t_image *) solong.objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "5"))
			mlx_put_image_to_window(solong.init, solong.win.window, elem, x, y);
		solong.objs = solong.objs->next;
	}
}
