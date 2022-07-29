#include "solong.h"

int	render(t_mlx *solong)
{
	if (!solong)
		return (1);
	return (0);
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

void	so_long(t_map *p_map)
{
	t_mlx	solong;
	t_list	*objs;
	t_list	*xpm_images;

	init_display(&solong, p_map);
	objs = gen_objects(p_map);
	xpm_images = gen_images(solong.init);
	// ------------------------------- //
	put_background(xpm_images, objs, &solong);

	t_image *img;
	int	x;
	int	y;

	while (objs)
	{
		img = (t_image *) objs->content;
		x = img->x;
		y = img->y;
		if (!ft_strcmp(img->name, "1"))
			mlx_put_image_to_window(solong.init, solong.win.window, xpm_images->next->content, x, y);
		if (!ft_strcmp(img->name, "2"))
			mlx_put_image_to_window(solong.init, solong.win.window, xpm_images->next->next->content, x, y);
		if (!ft_strcmp(img->name, "4"))
			mlx_put_image_to_window(solong.init, solong.win.window, xpm_images->next->next->next->next->content, x, y);
		if (!ft_strcmp(img->name, "5"))
			mlx_put_image_to_window(solong.init, solong.win.window, xpm_images->next->next->next->next->next->content, x, y);
		
		objs = objs->next;
	}

	// ------------------------------- //
	// mlx_put_image_to_window(void *mlx_ptr, void *mlx_win, void *img, x , y)
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	mlx_loop(solong.init);
	mlx_destroy_display(solong.init);
	// ft_objclear(&solong, objs);
	free(solong.init);
}

int	main(int argc, char **argv)
{
	t_map	v_map;

	
	if (argc < 2)
	{
		ft_printf("Cade o mapa jamanta?!\n");
		return (1);
	}
	if (!check_map(argv[1]))
		return (1);
	v_map = map_generator(argv[1]);
	so_long(&v_map);
	free(v_map.mapping);
	return (0);
}
