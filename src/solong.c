#include "solong.h"

int	render(t_mlx *solong)
{
	if (!solong)
		return (1);
	return (0);
}


void	so_long(t_map *p_map)
{
	t_mlx	solong;
	t_list	*objs;
	t_list	*xpm_images;

	init_display(&solong, p_map);
	objs = gen_objects(p_map);
	xpm_images = gen_images(solong.init);
	put_background(xpm_images, objs, &solong);
	// mlx_put_image_to_window(void *mlx_ptr, void *mlx_win, void *img, x , y)
	mlx_loop_hook(solong.init, render, &solong);
	events_hook(&solong);
	mlx_loop(solong.init);
	

	ft_lstclear(&objs, free);
	ft_destroy_images(solong.init, xpm_images);

	mlx_destroy_display(solong.init);
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
