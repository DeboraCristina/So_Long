#include "solong.h"

static void	*ft_find_image(t_list *imgs, char *index)
{
	int i;

	i = 0;
	while (i < ft_atoi(index))
	{
		imgs = imgs->next;
		i ++;
	}
	return (imgs->content);
}

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
	void	*elem;
	int	x;
	int	y;

	elem = ft_find_image(imgs, "1");

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "1"))
			mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
		objs = objs->next;
	}
}

void	put_player(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	void	*elem;
	int	x;
	int	y;

	elem = ft_find_image(imgs, "2");

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "2"))
		{
			mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
			break ;
		}
		objs = objs->next;
	}
}

void	put_exit(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	void	*elem;
	int	x;
	int	y;

	elem = ft_find_image(imgs, "3");

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "3"))
			mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
		objs = objs->next;
	}
}

void	put_collectable(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	void	*elem;
	int	x;
	int	y;

	elem = ft_find_image(imgs, "4");

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "4"))
			mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
		objs = objs->next;
	}
}

void	put_enemy(t_list *imgs, t_list *objs, t_mlx *solong)
{
	t_image	*img;
	void	*elem;
	int	x;
	int	y;

	elem = ft_find_image(imgs, "5");

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "5"))
			mlx_put_image_to_window(solong->init, solong->win.window, elem, x, y);
		objs = objs->next;
	}
}